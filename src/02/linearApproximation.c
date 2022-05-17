//
// Created by Manaki ITO on 2022/05/15.
//

#include "../common/type/linearDouble.h"
#include "../common/type/regressionCoefficient.h"

#include "../01/statisticalFunctions.c"
#include "../02/statisticalFunctions.c"

#include "linearApproximation.h"


regressionCoefficient calculateLinearExpression(linearDouble x, linearDouble y) {
    regressionCoefficient result = {0, 0};

    double covariance_xy = covariance(x, y);
    double variance_x = variance(x);

    double average_x = average(x);
    double average_y = average(y);

    double a = covariance_xy / variance_x;
    double b = average_y - (a * average_x);

    result.a = a;
    result.b = b;

    return result;
}
