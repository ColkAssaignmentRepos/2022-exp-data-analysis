//
// Created by Manaki ITO on 2022/05/16.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__02_STATICALFUNCTIONS_C
#define INC_2022_EXP_DATA_ANALYSIS__02_STATICALFUNCTIONS_C

#include <math.h>

#include "../common/type/linearDouble.h"
#include "../common/type/regressionCoefficient.h"
#include "../01/prototype.h"

#include "../01/statisticalFunctions.c"


double calculate_linear_function_value(regressionCoefficient linearFunction, double x) {
    return (linearFunction.a * x) + linearFunction.b;
}


double variance(linearDouble data) {
    double avg = average(data);

    double sum = 0;

    for (int i = 0; i < data.length; i++) {
        sum += pow((data.data[i] - avg), 2.0);
    }

    double result = sum / data.length;

    return result;
}


double coefficientOfDetermination(regressionCoefficient linearApproximation, linearDouble x, linearDouble y) {
    double total_variation = 0;
    double error_sum_of_squares = 0;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    double average_y = average(y);

    for (int i = 0; i < x.length; i++) {
        total_variation += pow((y.data[i] - calculate_linear_function_value(linearApproximation, x.data[i])), 2.0);
        error_sum_of_squares += pow((y.data[i] - average_y), 2.0);
    }

    double result = 1 - (total_variation / error_sum_of_squares);

    return result;
}

#endif //INC_2022_EXP_DATA_ANALYSIS__02_STATICALFUNCTIONS_C
