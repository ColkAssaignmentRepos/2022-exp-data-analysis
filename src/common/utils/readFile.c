//
// Created by Manaki ITO on 2022/05/10.
//

#include <stdlib.h>
#include <stdio.h>

#include "../macro/myErrors.h"
#include "./readFile.h"

#define CHARS_IN_ONE_LINE_LIMIT 5000
#define RO_FILE_OPEN_MODE "r"


readData readFile(char file_name[]) {
    const char open_mode[] = RO_FILE_OPEN_MODE;

    linearDouble data_x = {0, NULL};
    linearDouble data_y = {0, NULL};

    readData retval = {UNKNOWN_ERROR, data_x, data_y};

    FILE *fp = fopen(file_name, open_mode);
    if (fp == NULL) {
        return retval;
    }

    unsigned int num_of_data = 0;

    char num_of_data_raw[CHARS_IN_ONE_LINE_LIMIT];
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

    for (int i = 0; i < num_of_data; i++) {
        fscanf(fp, "%lf %lf", &data_x.data[i], &data_y.data[i]);
    }

    fclose(fp);

    retval.err = 0;
    retval.x = data_x;
    retval.y = data_y;

    return retval;
}
