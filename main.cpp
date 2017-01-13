#include "matrix.h"
#include "lu.h"

// solve system of linear equations Ax=b
// LU matrix decomposition: A=LU
// L - lower triangular matrix L and U - upper triangular matrix
// solve system of equations LUx=b
// first forward substitution Ly=b
// then backward substitution Ux=y
// author: Wojciech Mormul
// date: 14.11.2015

using namespace std;

int N=7;

int main()
{
    cout<<endl<<"=================== LU matrix decomposition ===================="<<endl<<endl;

    srand(time(0));

    Matrix A(N,N,"A",Matrix::as_matrix);A.random(5,10);
    Matrix b(N,1,"b",Matrix::as_vector);b.random(5,10);

    LU_decomp lu_decomp(N);
    lu_decomp.find_decomposition(A);
    lu_decomp.forward_substitution(b);
    lu_decomp.backward_substitution();

    A.draw();
    b.draw();
    lu_decomp.L->draw();
    lu_decomp.U->draw();
    lu_decomp.x->draw();

    return 0;
}
