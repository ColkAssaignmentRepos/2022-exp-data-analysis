//
// Created by Manaki ITO on 2022/05/19.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__LINEARFUNCTION_H
#define INC_2022_EXP_DATA_ANALYSIS__LINEARFUNCTION_H

#include "../common/type/linearFunctionParameters.h"

#include "./mathematicalFunctionIF.h"


// Example of implementation of MathematicalFunctionIF
typedef struct {
    MathematicalFunctionsInterface interface;
    linearFunctionParameters parameters;
} LinearFunction;


void linearFunctionConstruct(LinearFunction* p_this, linearFunctionParameters parameters);


#endif //INC_2022_EXP_DATA_ANALYSIS__LINEARFUNCTION_H
