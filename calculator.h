#ifndef CALCULATOR_H
#define CALCULATOR_H

typedef struct _Calculator {

    double (**operations)(int, int);
    int **data;
    int operationCount;
    int dataLength;

    } Calculator;

    Calculator* create_calculator(double (**operations)(int, int), int operationCount);

    bool load_calculator_data(Calculator*, char*);

    void run_calculator(Calculator*);

    bool destory_calculator(Calculator*);

    double add_calculator(int, int);

    double sub_calculator(int, int);

    double mul_calculator(int, int);

    double div_calculator(int, int);

    double mod_calculator(int, int);

#endif
