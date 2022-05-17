//
// Created by Manaki ITO on 2022/05/06.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__READFILE_H
#define INC_2022_EXP_DATA_ANALYSIS__READFILE_H

#include "type/linearDouble.h"

typedef struct {
    int err;
    linearDouble x;
    linearDouble y;
} readData;

readData readFile(char file_name[]);

#endif //INC_2022_EXP_DATA_ANALYSIS__READFILE_H
