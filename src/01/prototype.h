//
// Created by Manaki ITO on 2022/05/06.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__PROTOTYPE_H
#define INC_2022_EXP_DATA_ANALYSIS__PROTOTYPE_H

#include "../common/type/linearDouble.h"
#include "../common/readFile.h"

// Promise all of following functions are non-destructive

double sum(linearDouble data);
double sumOfSquares(linearDouble data);
double average(linearDouble data);
linearDouble deviation(linearDouble data);
double standardDeviation(linearDouble data);
double covariance(linearDouble x, linearDouble y);
double correlationCoefficient(linearDouble x, linearDouble y);

#endif //INC_2022_EXP_DATA_ANALYSIS__PROTOTYPE_H
