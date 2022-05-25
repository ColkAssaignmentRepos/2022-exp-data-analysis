//
// Created by Manaki ITO on 2022/05/19.
//

#include "../common/macro/myErrors.h"

#include "../common/utils/readFile.h"

#include "../common/statics/staticalFunctions.h"

#include "./quadraticApproximation.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    quadraticFunctionParameters approximation = quadraticApproximation(data.x, data.y);
    double coefficient_of_determination = coefficientOfDeterminationQuadratic(approximation, data.x, data.y);

    printf("y = %lf x2 + %lf x + %lf\n",
           approximation.a, approximation.b, approximation.c);

    printf("R2 = %lf\n",
           coefficient_of_determination);

    freeLinearDouble(&data.x);
    freeLinearDouble(&data.y);

    return NO_ERROR;
}
