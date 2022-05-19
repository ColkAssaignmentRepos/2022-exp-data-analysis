//
// Created by Manaki ITO on 2022/05/06.
//
#include <stdio.h>
#include <stdlib.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"

#include "../common/statics/staticalFunctions.h"

#include "../common/utils/readFile.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    double average_x = average(data.x);
    double average_y = average(data.y);

    double standard_deviation_x = standardDeviation(data.x);
    double standard_deviation_y = standardDeviation(data.y);

    double covariance_xy = covariance(data.x, data.y);
    double correlation_coefficient_xy = correlationCoefficient(data.x, data.y);

    printf("ave-x = %lf\nave-y = %lf\nsd-x = %lf\nsd-y = %lf\ncov = %lf\nrel = %lf\n",
           average_x, average_y, standard_deviation_x, standard_deviation_y, covariance_xy, correlation_coefficient_xy);

    freeLinearDouble(&data.x);
    freeLinearDouble(&data.y);

    return NO_ERROR;
}
