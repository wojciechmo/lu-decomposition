#include "lu.h"

LU_decomp::LU_decomp(int size)
{
    N=size;

    L=new Matrix(N,N,"L",Matrix::as_matrix);
    U=new Matrix(N,N,"U",Matrix::as_matrix);
    mk=new Matrix(N,N,"mk",Matrix::as_matrix);

    x=new Matrix(N,1,"x",Matrix::as_vector);
    y=new Matrix(N,1,"y",Matrix::as_vector);
}

int LU_decomp::multiply (Matrix *m1, Matrix *m2, Matrix *y)
{
    if(m1->cols!=m2->rows)
        return 0;

    double suma;
    for(int i=0;i<m1->rows;i=i+1)
    {
        for(int j=0;j<m2->cols;j=j+1)
        {
            suma=0;
            for(int k=0;k<m1->cols;k=k+1)
                suma=suma+m1->mat[i][k]*m2->mat[k][j];

            y->mat[i][j]=suma;
        }
    }

    return 1;
}

void LU_decomp::find_decomposition(Matrix &A)
{
    for(int i=0;i<N;i=i+1)
    for(int j=0;j<N;j=j+1)
    {
        if(i==j)
            L->mat[i][j]=1;
        else
            L->mat[i][j]=0;
    }

    for(int i=0;i<N;i=i+1)
    for(int j=0;j<N;j=j+1)
        U->mat[i][j]=A.mat[i][j];

    for(int i=0;i<N;i=i+1)
    {
        for(int i1=0;i1<N;i1=i1+1)
        for(int j1=0;j1<N;j1=j1+1)
            mk->mat[i1][j1]=0;

        for(int i1=0;i1<N;i1=i1+1)
            mk->mat[i1][i1]=1;

        for(int k=i+1;k<N;k=k+1)
            mk->mat[k][i]=-U->mat[k][i]/U->mat[i][i];

        multiply(mk,U,U);

        for(int k=i+1;k<N;k=k+1)
            mk->mat[k][i]=-mk->mat[k][i];

        multiply(L,mk,L);
    }
}

void LU_decomp::forward_substitution(Matrix &b)
{
    double suma;
    for(int i=0;i<N;i=i+1)
    {
        suma=0;
        for(int j=0;j<i;j=j+1)
            suma=suma+L->mat[i][j]*y->mat[j][0];

        y->mat[i][0]=(b.mat[i][0]-suma)/L->mat[i][i];
    }
}

void LU_decomp::backward_substitution()
{
    double suma;
    for(int i=N-1;i>=0;i=i-1)
    {
        suma=0;
        for(int j=N-1;j>i;j=j-1)
            suma=suma+U->mat[i][j]*x->mat[j][0];

        x->mat[i][0]=(y->mat[i][0]-suma)/U->mat[i][i];
    }
}
