//
// Created by Manaki ITO on 2022/05/19.
//

#include <math.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"

#include "../common/statics/staticalFunctions.h"

#include "./mathematicalFunctionIF.h"

#include "generalCoefficientOfDetermination.h"


double generalCoefficientOfDetermination(MathematicalFunctionsInterface* p_function, linearDouble x, linearDouble y) {
    double total_variation = 0;
    double error_sum_of_squares = 0;

    if (x.length != y.length) {
        kill_exit(INVALID_DATA_FORMAT, INVALID_DATA_FORMAT_ERR_MSG);
    }

    double average_y = average(y);

    for (int i = 0; i < x.length; i++) {
        total_variation += pow((y.data[i] - p_function->p_methods->calculateValue(p_function, x.data[i])), 2.0);
        error_sum_of_squares += pow((y.data[i] - average_y), 2.0);
    }

    double result = 1 - (total_variation / error_sum_of_squares);

    return result;
}
