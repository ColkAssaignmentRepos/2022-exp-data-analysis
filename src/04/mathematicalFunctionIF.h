//
// Created by Manaki ITO on 2022/05/19.
//

#ifndef INC_2022_EXP_DATA_ANALYSIS__MATHEMATICALFUNCTIONIF_H
#define INC_2022_EXP_DATA_ANALYSIS__MATHEMATICALFUNCTIONIF_H


struct mathematicalfunctionsinterfacemethods;


typedef struct {
    const struct mathematicalfunctionsinterfacemethods *p_methods;
} MathematicalFunctionsInterface;


typedef struct mathematicalfunctionsinterfacemethods {
    double (*calculateValue) (MathematicalFunctionsInterface* const p_this, const double x);
} MathematicalFunctionsInterfaceMethods;


#endif //INC_2022_EXP_DATA_ANALYSIS__MATHEMATICALFUNCTIONIF_H
