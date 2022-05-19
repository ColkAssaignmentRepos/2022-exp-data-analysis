//
// Created by Manaki ITO on 2022/05/19.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__STATICALFUNCTIONS_H
#define INC_2022_EXP_DATA_ANALYSIS__STATICALFUNCTIONS_H

#include "../../common/type/linearDouble.h"
#include "../../common/type/linearFunctionParameters.h"
#include "../../common/type/quadraticFunctionParameters.h"


double sum(linearDouble data);

double average(linearDouble data);

double variance(linearDouble data);

linearDouble deviation(linearDouble data);

double covariance(linearDouble x, linearDouble y);

double standardDeviation(linearDouble data);

double correlationCoefficient(linearDouble x, linearDouble y);

double linearFunctionValue(linearFunctionParameters linearFunction, double x);

double coefficientOfDeterminationLinear(linearFunctionParameters linearApproximation, linearDouble x, linearDouble y);

double quadraticFunctionValue(quadraticFunctionParameters quadratic_function, double x);

double coefficientOfDeterminationQuadratic(quadraticFunctionParameters quadratic_approximation, linearDouble x, linearDouble y);


#endif //INC_2022_EXP_DATA_ANALYSIS__STATICALFUNCTIONS_H
