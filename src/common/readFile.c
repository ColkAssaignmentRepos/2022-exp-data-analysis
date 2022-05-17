//
// Created by Manaki ITO on 2022/05/10.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS_READFILE_C
#define INC_2022_EXP_DATA_ANALYSIS_READFILE_C

#include <stdlib.h>
#include <stdio.h>

#include "macro/myErrors.h"
#include "./readFile.h"
#include "type/linearDouble.c"

#define CHARS_IN_ONE_LINE_LIMIT 5000
#define RO_FILE_OPEN_MODE "r"


readData readFile(char file_name[]) {
    const char open_mode[] = RO_FILE_OPEN_MODE;

    linearDouble data_x;
    linearDouble data_y;

    readData retval = {UNKNOWN_ERROR, data_x, data_y};

    FILE *fp = fopen(file_name, open_mode);
    if (fp == NULL) {
        return retval;
    }

    unsigned int num_of_data = 0;

    char num_of_data_raw[CHARS_IN_ONE_LINE_LIMIT + 3];
    if (fgets(num_of_data_raw, CHARS_IN_ONE_LINE_LIMIT, fp) == NULL) {
        kill_exit(INVALID_DATA_FORMAT, UNABLE_TO_READ_FILE_ERR_MSG);
    }

    char **strtol_end_ptr = NULL;
    num_of_data = strtol(num_of_data_raw, strtol_end_ptr, 10);
    if (num_of_data == 0) {
        kill_exit(INVALID_DATA_FORMAT, UNABLE_TO_READ_FILE_ERR_MSG);
    }

    data_x = initLinearDouble(num_of_data);
    data_y = initLinearDouble(num_of_data);

    int fscanf_error;
    for (int i = 0; i < num_of_data; i++) {
        fscanf_error = fscanf(fp, "%lf %lf", &data_x.data[i], &data_y.data[i]);
    }

    retval.err = 0;
    retval.x = data_x;
    retval.y = data_y;

    return retval;
}

#endif //INC_2022_EXP_DATA_ANALYSIS_READFILE_C
