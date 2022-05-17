//
// Created by Manaki ITO on 2022/05/06.
//
#include <stdio.h>
#include <stdlib.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"
#include "../common/type/regressionCoefficient.h"
#include "../common/readFile.h"

#include "../common/readFile.c"
#include "./linearApproximation.c"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    regressionCoefficient regression_coefficient = calculateLinearExpression(data.x, data.y);
    double coefficient_of_determination = coefficientOfDetermination(regression_coefficient, data.x, data.y);

    printf("y = %lf x + %lf\n",
           regression_coefficient.a, regression_coefficient.b);
    printf("R2 = %lf\n",
           coefficient_of_determination);

    // printf("(");
    // for (int i = 0; i < data.x.length; i++) {
    //     printf("%lf,", data.x.data[i]);
    // }
    // printf(")\n");

    return NO_ERROR;
}
