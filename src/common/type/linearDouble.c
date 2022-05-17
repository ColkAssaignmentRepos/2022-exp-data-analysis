//
// Created by Manaki ITO on 2022/05/10.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_C
#define INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_C

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../common/macro/myErrors.h"
#include "./linearDouble.h"


linearDouble initLinearDouble(unsigned int length) {
    double *ptr = NULL;
    linearDouble retval = {0, NULL};

    ptr = (double *) malloc(sizeof(double) * length);
    if (ptr == NULL) {
        return retval;
    }

    retval.length = length;
    retval.data = ptr;

    return retval;
}

bool isInitializedLinear (linearDouble *data) {
    if (data->data == NULL || data->length == 0) {
        return false;
    }

    return true;
}

int freeLinearDouble(linearDouble *data) {
    free(data->data);
    data->length = 0;

    return NO_ERROR;
}

linearDouble copyLinearDouble(linearDouble *from) {
    double *dest = NULL;
    linearDouble retval = {0, NULL};

    dest = memcpy(dest, from->data, sizeof(&from->data));
    if (dest == NULL) {
        return retval;
    }

    retval.length = from->length;
    retval.data = dest;

    return retval;
}

#endif //INC_2022_EXP_DATA_ANALYSIS__LINEARDOUBLE_H
