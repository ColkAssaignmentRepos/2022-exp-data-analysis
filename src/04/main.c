//
// Created by Manaki ITO on 2022/05/19.
//
#include <stdio.h>
#include <stdlib.h>

#include "../common/macro/myErrors.h"

#include "../common/type/linearDouble.h"
#include "../common/type/linearFunctionParameters.h"

#include "../common/utils/readFile.h"

#include "./linearFunction.h"

#include "./mathematicalFunctionIF.h"

#include "./generalCoefficientOfDetermination.h"

#include "../02/linearApproximation.h"


int main(int argc, char *argv[]) {
    // Declare LinearFunction type variable
    LinearFunction approximation;

    if (argc != 2) {
        kill_exit(-1, UNEXPECTED_ARGUMENTS_ERR_MSG);
    }

    char *path_to_file = argv[1];

    readData data = readFile(path_to_file);
    if (data.err != NO_ERROR) {
        kill_exit(-1, UNABLE_TO_OPEN_FILE_ERR_MSG);
    }

    linearFunctionParameters regression_coefficient = linearApproximation(data.x, data.y);

    // Call the constructor of LinearFunction and initialize its data with calculated approximation
    linearFunctionConstruct(&approximation, regression_coefficient);

    double coefficient_of_determination = generalCoefficientOfDetermination(
            (MathematicalFunctionsInterface *) &approximation,
            data.x, data.y);

    printf("// Calculated R2 with generalCoefficientOfDetermination()!\n");

    printf("y = %lf x + %lf\n",
           regression_coefficient.a, regression_coefficient.b);

    printf("R2 = %lf\n",
           coefficient_of_determination);

    freeLinearDouble(&data.x);
    freeLinearDouble(&data.y);

    return NO_ERROR;
}
