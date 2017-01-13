#ifndef LU_H
#define LU_H

#include "matrix.h"

class LU_decomp
{
public:

    LU_decomp(int size);

    int N=7;
    Matrix *U;
    Matrix *L;
    Matrix *y;
    Matrix *x;
    Matrix *mk;

    void find_decomposition(Matrix &A);
    void forward_substitution(Matrix &b);
    void backward_substitution();
    int multiply (Matrix *m1, Matrix *m2, Matrix *y);
};

#endif // LU_H
