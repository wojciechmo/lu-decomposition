#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

class Matrix
{
public:

    Matrix(int M, int N,string c_name,int c_type );
    ~Matrix();

    double **mat;
    int rows;
    int cols;
    string name;
    int type;
    const static int as_matrix=1;
    const static int as_vector=2;

    void draw();
    void random(double a,double b);
};

#endif // MATRIX_H
