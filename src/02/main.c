//
// Created by Manaki ITO on 2022/05/06.
//
#include <stdio.h>
#include <stdlib.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"
#include "../common/type/linearFunctionParameters.h"

#include "../common/utils/readFile.h"

#include "../common/statics/staticalFunctions.h"

#include "./linearApproximation.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    linearFunctionParameters regression_coefficient = linearApproximation(data.x, data.y);
    double coefficient_of_determination = coefficientOfDeterminationLinear(regression_coefficient, data.x, data.y);

    printf("y = %lf x + %lf\n",
           regression_coefficient.a, regression_coefficient.b);
    printf("R2 = %lf\n",
           coefficient_of_determination);

    return NO_ERROR;
}
