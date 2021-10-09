#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Matrix3D
{
private:
    double mat[3][3];
public:
    Matrix3D()
    {
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
                mat[i][j] = 0;
        }
    }

    Matrix3D(double X[3][3])
    {
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
                mat[i][j] = X[i][j];
        }
    }

    ~Matrix3D() {}
    void setMatrix()
    {
        cout << "Input the matrix: \n";
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
                cin >> mat[i][j];
        }
    }
    void show()
    {
        cout << "----------The Matrix----------"<<endl;
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
                cout << mat[i][j] << " ";
            cout <<endl<<endl;
        }
    }
    double det ()
    {
        double DET = 0;
        for(int i=0; i<3; i++)
        {
            DET = DET + (mat[0][i]* (mat[1][(i + 1) % 3] * mat[2][( i + 2) % 3] - mat[1][(i + 2) % 3]*mat[2][(i + 1) % 3]));
        }
        return DET;
    }
    Matrix3D inverse()
    {
        Matrix3D ret;
        double DET = det();
        if (DET == 0)
        {
            cout << "The inverse of this matrix doesn't exist";
            exit(0);
        }
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
            {
                ret.mat[i][j] = ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) - (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) / DET;
            }
        }
        return ret;
    }
    Matrix3D operator + (Matrix3D b)
    {
        Matrix3D ret;
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
            {
                ret.mat[i][j] = mat[i][j] + b.mat[i][j];
            }
        }
        return ret;
    }
    Matrix3D operator - (Matrix3D b)
    {
        Matrix3D ret;
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
            {
                ret.mat[i][j] = mat[i][j] - b.mat[i][j];
            }
        }
        return ret;
    }
    Matrix3D operator * (Matrix3D b)
    {
        Matrix3D ret, a(mat);
        for(int i=0; i<3; ++i)
        {
            for(int j=0; j<3; ++j)
            {
                for(int k=0; k<3; ++k)
                {
                    ret.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                }
            }
        }
        return ret;
    }
};

int main()
{
    double x[3][3] = {{2,9,0}, {2,55,69}, {35,6,13}};
    double y[3][3] = {{3,42,9}, {20, 4, 54}, {83, 78, 62}};

    Matrix3D mat1(x), mat2(y);
    Matrix3D mat3 = mat1 + mat2;
    Matrix3D mat4 = mat1 - mat2;
    Matrix3D mat5 = mat1 * mat2;
    Matrix3D mat6 = mat1.inverse();

    mat2.show();
    mat3.show();
    mat4.show();
    mat5.show();
    mat6.show();
}
