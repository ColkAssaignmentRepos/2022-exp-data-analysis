//
// Created by Manaki ITO on 2022/05/15.
//

#include "../common/type/linearDouble.h"
#include "../common/type/linearFunctionParameters.h"

#include "../common/statics/staticalFunctions.h"

#include "./linearApproximation.h"


linearFunctionParameters linearApproximation(linearDouble x, linearDouble y) {
    linearFunctionParameters result = {0, 0};

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
