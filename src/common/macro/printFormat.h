//
// Created by Manaki ITO on 2022/05/11.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__PRINTFORMAT_H
#define INC_2022_EXP_DATA_ANALYSIS__PRINTFORMAT_H

#include <stdio.h>

#define print_green(...) {printf("\x1b[32m"); printf(__VA_ARGS__); printf("\x1b[39m\n");}
#define blank() {printf("\n");}

#endif //INC_2022_EXP_DATA_ANALYSIS__PRINTFORMAT_H
