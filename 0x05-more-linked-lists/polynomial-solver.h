#ifndef POLYNOMIAL_SOLVER_H
#define POLYNOMIAL_SOLVER_H

typedef struct Term {
    int coeff;
    int exp;
    struct Term* next;
} Term;

endif