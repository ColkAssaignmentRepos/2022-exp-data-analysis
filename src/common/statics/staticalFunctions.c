//
// Created by Manaki ITO on 2022/05/17.
//

#include <stdlib.h>
#include <math.h>

#include "../../common/macro/myErrors.h"

#include "../../common/type/linearDouble.h"
#include "../../common/type/linearFunctionParameters.h"
#include "../../common/type/quadraticFunctionParameters.h"

#include "./staticalFunctions.h"


double sum(linearDouble data) {
    double sum = 0;

    for (int i = 0; i < data.length; i++) {
        sum += data.data[i];
    }

    return sum;
}


double average(linearDouble data) {
    double data_sum = sum(data);

    double avg = data_sum / data.length;

    return avg;
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


linearDouble deviation(linearDouble data) {
    linearDouble result = initLinearDouble(data.length);

    double avg = average(data);

    for (int i = 0; i < data.length; i++) {
        result.data[i] = data.data[i] - avg;
    }

    return result;
}


double covariance(linearDouble x, linearDouble y) {
    linearDouble deviation_x;
    linearDouble deviation_y;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    deviation_x = deviation(x);
    deviation_y = deviation(y);

    double sum_of_deviations = 0;

    for (int i = 0; i < x.length; i++) {
        sum_of_deviations += deviation_x.data[i] * deviation_y.data[i];
    }

    double result = sum_of_deviations / x.length;

    freeLinearDouble(&deviation_x);
    freeLinearDouble(&deviation_y);

    return result;
}


double standardDeviation(linearDouble data) {
    double result = 0;
    double self_covariance = covariance(data, data);

    result = sqrt(self_covariance);

    return result;
}


double correlationCoefficient(linearDouble x, linearDouble y) {
    double covariance_of_data = covariance(x, y);
    double standard_deviation_x = standardDeviation(x);
    double standard_deviation_y = standardDeviation(y);

    double result = covariance_of_data / (standard_deviation_x * standard_deviation_y);

    return result;
}


double linearFunctionValue(linearFunctionParameters linearFunction, double x) {
    return (linearFunction.a * x) + linearFunction.b;
}


double coefficientOfDeterminationLinear(linearFunctionParameters linearApproximation, linearDouble x, linearDouble y) {
    double total_variation = 0;
    double error_sum_of_squares = 0;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    double average_y = average(y);

    for (int i = 0; i < x.length; i++) {
        total_variation += pow((y.data[i] - linearFunctionValue(linearApproximation, x.data[i])), 2.0);
        error_sum_of_squares += pow((y.data[i] - average_y), 2.0);
    }

    double result = 1 - (total_variation / error_sum_of_squares);

    return result;
}


double quadraticFunctionValue(quadraticFunctionParameters quadratic_function, double x) {
    return (quadratic_function.a * x * x) + (quadratic_function.b * x) + quadratic_function.c;
}


double coefficientOfDeterminationQuadratic(quadraticFunctionParameters quadratic_approximation, linearDouble x, linearDouble y) {
    double total_variation = 0;
    double error_sum_of_squares = 0;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    double average_y = average(y);

    for (int i = 0; i < x.length; i++) {
        total_variation += pow((y.data[i] - quadraticFunctionValue(quadratic_approximation, x.data[i])),
                               2.0);
        error_sum_of_squares += pow((y.data[i] - average_y), 2.0);
    }

    double result = 1 - (total_variation / error_sum_of_squares);

    return result;
}
