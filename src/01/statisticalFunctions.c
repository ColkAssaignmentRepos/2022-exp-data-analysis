//
// Created by Manaki ITO on 2022/05/13.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__01_STATICALFUNCTIONS_C
#define INC_2022_EXP_DATA_ANALYSIS__01_STATICALFUNCTIONS_C

#include <stdlib.h>
#include <math.h>

#include "../common/macro/myErrors.h"
#include "./prototype.h"


double sum(linearDouble data) {
    double sum = 0;

    for (int i = 0; i < data.length; i++) {
        sum += data.data[i];
    }

    return sum;
}

double sumOfSquares(linearDouble data) {
    double sum = 0;

    for (int i = 0; i < data.length; i++) {
        sum += pow(data.data[i], 2.0);
    }

    return sum;
}

double average(linearDouble data) {
    double data_sum = sum(data);

    double avg = data_sum / data.length;

    return avg;
}

linearDouble deviation(linearDouble data) {
    linearDouble result = initLinearDouble(data.length);

    double avg = average(data);

    for (int i = 0; i < data.length; i++) {
        result.data[i] = data.data[i] - avg;
    }

    return result;
}

double standardDeviation(linearDouble data) {
    double result = 0;
    double self_covariance = covariance(data, data);

    result = sqrt(self_covariance);

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

    return result;
}

double correlationCoefficient(linearDouble x, linearDouble y) {
    double covariance_of_data = covariance(x, y);
    double standard_deviation_x = standardDeviation(x);
    double standard_deviation_y = standardDeviation(y);

    double result = covariance_of_data / (standard_deviation_x * standard_deviation_y);

    return result;
}

#endif //INC_2022_EXP_DATA_ANALYSIS__01_STATICALFUNCTIONS_C
