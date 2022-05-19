//
// Created by Manaki ITO on 2022/05/10.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../../common/macro/myErrors.h"

#include "./linearDouble.h"


linearDouble createEmptyLinearDouble() {
    linearDouble retval = {0, NULL};

    return retval;
}


linearDouble initLinearDouble(unsigned int length) {
    double *ptr = NULL;
    linearDouble retval = createEmptyLinearDouble();

    ptr = (double *) malloc(sizeof(double) * length);
    if (ptr == NULL) {
        return retval;
    }

    retval.length = length;
    retval.data = ptr;

    return retval;
}


bool isInitializedLinear(linearDouble *data) {
    if (data->data == NULL) {
        return false;
    }

    return true;
}


int freeLinearDouble(linearDouble *data) {
    free(data->data);
    data->length = 0;

    return NO_ERROR;
}
