# LU decomposition

The objective is to solve system of linear equations Ax=b with LU decomposition, which factors matrix A as a product of lower triangular matrix L and upper triangular matrix U. Analyzed system of linear equations then becomes: LUx=b. First solve Ly=b with forward substitution, then solve Ux=y with backward substitution.


<img src="https://github.com/WojciechMormul/lu-decomposition/blob/master/imgs/lu.png" width="500">
