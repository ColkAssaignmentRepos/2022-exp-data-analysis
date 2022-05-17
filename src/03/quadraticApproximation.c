//
// Created by Manaki ITO on 2022/05/16.
//

#include <math.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"
#include "../common/readFile.h"

#include "../common/readFile.c"

#include "../common/type/quadraticFunction.h"

#include "../01/statisticalFunctions.c"


quadraticFunction quadraticApproximation(linearDouble x, linearDouble y) {
    double a, b, c = 0;

    double X = 0;
    double X2 = 0;
    double X3 = 0;
    double X4 = 0;
    double Y = 0;
    double XY = 0;
    double X2Y = 0;

    double x_1 = 0;
    double x_2 = 0;
    double x_3 = 0;
    double x_4 = 0;

    double y_1 = 0;

    double x_1_y_1 = 0;
    double x_2_y_1 = 0;

    for (int i = 0; i < x.length; i++) {
        x_1 = x.data[i];
        x_2 = x_1 * x_1;
        x_3 = x_2 * x_1;
        x_4 = x_3 * x_1;

        y_1 = y.data[i];

        x_1_y_1 = x_1 * y_1;
        x_2_y_1 = x_2 * y_1;


        X += x_1;
        X2 += x_2;
        X3 += x_3;
        X4 += x_4;

        Y += y_1;

        XY += x_1_y_1;
        X2Y += x_2_y_1;
    }

    unsigned int N = x.length;

    double A = ((2 * X) * (X2) * (X3)) + (N * X2 * X4) - (X * X * X4) - (N * X3 * X3) - (X2 * X2 * X2);

    // a0
    c = ((-1 * X2 * X2 * X2Y) + (X * X3 * X2Y) - (X * X4 * XY) + (X2 * X3 * XY) - (X3 * X3 * Y) + (X2 * X4 * Y)) / (A);
    // a1
    b = ((X * X2 * X2Y) - (N * X3 * X2Y) + (N * X4 * XY) - (X2 * X2 * XY) + (X2 * X3 * Y) - (X * X4 * Y)) / (A);
    // a2
    a = ((N * X2 * X2Y) - (X * X * X2Y) + (X * X2 * XY) - (N * X3 * XY) + (X * X3 * Y) - (X2 * X2 * Y)) / (A);

    quadraticFunction result = {a, b, c};

    return result;
}

double calculate_quadratic_function_value(quadraticFunction quadratic_function, double x) {
    return (quadratic_function.a * x * x) + (quadratic_function.b * x) + quadratic_function.c;
}


double coefficientOfDeterminationQuadratic(quadraticFunction quadratic_approximation, linearDouble x, linearDouble y) {
    double total_variation = 0;
    double error_sum_of_squares = 0;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    double average_y = average(y);

    for (int i = 0; i < x.length; i++) {
        total_variation += pow((y.data[i] - calculate_quadratic_function_value(quadratic_approximation, x.data[i])), 2.0);
        error_sum_of_squares += pow((y.data[i] - average_y), 2.0);
    }

    double result = 1 - (total_variation / error_sum_of_squares);

    return result;
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    quadraticFunction approximation = quadraticApproximation(data.x, data.y);
    double coefficient_of_determination = coefficientOfDeterminationQuadratic(approximation, data.x, data.y);

    printf("y = %lf x2 + %lf x + %lf\n",
           approximation.a, approximation.b, approximation.c);

    printf("R2 = %lf\n",
           coefficient_of_determination);

    return NO_ERROR;
}
