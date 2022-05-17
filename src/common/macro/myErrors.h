//
// Created by Manaki ITO on 2022/05/06.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__MYERRORS_H
#define INC_2022_EXP_DATA_ANALYSIS__MYERRORS_H

#include <stdio.h>

#define print_error(...) {fprintf(stderr, "\x1b[31m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\x1b[39m\n");}
#define kill_exit(exit_code, ...) {print_error(__VA_ARGS__); exit(exit_code);}

#define NO_ERROR 0
#define UNKNOWN_ERROR (-1)
#define INVALID_DATA_FORMAT 1

#define UNEXPECTED_ARGUMENTS_ERR_MSG "[X] Unexpected Arguments Error: Illegal arguments."
#define UNABLE_TO_OPEN_FILE_ERR_MSG "[X] Unable to Open File: Can't open specified file. Make sure the file path is correct."
#define INVALID_DATA_FORMAT_ERR_MSG "[X] The Format Invalid: The format of the passed data is invalid. Make sure the format is correct."
#define UNABLE_TO_READ_FILE_ERR_MSG "[X] Unable to Read File Error: Can't read the file properly. Is the format of the file correct?"

#endif //INC_2022_EXP_DATA_ANALYSIS__MYERRORS_H
