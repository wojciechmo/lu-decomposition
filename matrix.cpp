#include "matrix.h"

Matrix::Matrix(int M,int N,string c_name,int c_type)
{
    rows=M;cols=N;
    name=c_name;
    type=c_type;

    mat=new double*[rows];
    for(int i=0;i<rows;i=i+1)
        mat[i]=new double[cols];
}

Matrix::~Matrix()
{
    for(int i=0;i<rows;i=i+1)
    {
        delete[]mat[i];
    }
    delete []mat;
}

void Matrix::draw()
{
    if(type==as_matrix)
    {
        cout<<"Matrix "<<name<<": "<<endl;

        for(int i=0;i<rows;i=i+1)
        {
            for(int j=0;j<cols;j=j+1)
            {
                if(mat[i][j]<10E-13&&mat[i][j]>-10E-13)
                    mat[i][j]=0;

                cout<<setprecision(3)<<setw(11)<<left<<mat[i][j];
            }

            cout<<setw(0)<<endl;
        }
        cout<<endl;
    }

    else if(type==as_vector)
    {
        cout<<"Vector "<<name<<": "<<endl;

        for(int i=0;i<rows;i=i+1)
        {
            if(mat[i][0]<10E-13&&mat[i][0]>-10E-13)
                mat[i][0]=0;

            cout<<setprecision(3)<<setw(11)<<left<<mat[i][0];
        }
        cout<<setw(0)<<endl<<endl;
    }
}

void Matrix::random(double a,double b)
{
    if(b<a){double c=b;b=a;a=c;}
    double width=b-a;

    for(int i=0;i<rows;i=i+1)
    for(int j=0;j<cols;j=j+1)
        mat[i][j]=width*rand()/double(RAND_MAX)+a;
}
