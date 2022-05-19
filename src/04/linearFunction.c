//
// Created by Manaki ITO on 2022/05/19.
//

#include "./mathematicalFunctionIF.h"

#include "linearFunction.h"


static double calculateValue (MathematicalFunctionsInterface* const p_this, const double x) {
    LinearFunction* const p = (LinearFunction* const)p_this;

    double result = (p->parameters.a * x) + (p->parameters.b);

    return result;
}


static const MathematicalFunctionsInterfaceMethods LINEAR_FUNCTION_METHODS = {
    calculateValue
};


void linearFunctionConstruct(LinearFunction* p_this, linearFunctionParameters parameters) {
    ((MathematicalFunctionsInterface*)p_this)->p_methods = &LINEAR_FUNCTION_METHODS;

    p_this->parameters = parameters;
}
