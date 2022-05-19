//
// Created by Manaki ITO on 2022/05/06.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_H
#define INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_H

#include <stdbool.h>


typedef struct {
    unsigned length;
    double *data;
} linearDouble;

linearDouble initLinearDouble(unsigned int length);

bool isInitializedLinear(linearDouble *data);

int freeLinearDouble(linearDouble *data);


#endif //INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_H
