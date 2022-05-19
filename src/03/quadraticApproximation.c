//
// Created by Manaki ITO on 2022/05/16.
//

#include "../common/type/linearDouble.h"
#include "../common/type/quadraticFunction.h"

#include "./quadraticApproximation.h"


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
