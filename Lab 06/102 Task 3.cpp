#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class rationalNumber
{
private:
    int ntr,dtr;

    void check_val()
    {
        if(dtr==0)
        {
            cout<<"THe denominator cannot be zero"<<endl;
        }
    }

public:
    rationalNumber() {}

    void getValues()
    {
        cout<<"The numerator: "<<ntr<<endl;
        cout<<"The denominator:"<<dtr<<endl;
    }
    void assign_Val(int x, int y)
    {
        ntr=x;
        dtr=y;
        check_val();
    }
    ~rationalNumber() {}
    double convert()
    {
        double R= (double)ntr/(double)dtr;
        return R;
    }
    double operator + (rationalNumber ADD)

    {
        return (double)ntr/dtr + (double)ADD.ntr/ADD.dtr;
    }
    double operator - (rationalNumber SUB)
    {
        return (double)ntr/dtr - (double)SUB.ntr/SUB.dtr;
    }
    double operator * (rationalNumber MUL)
    {
        return (double)ntr/dtr * (double)MUL.ntr/MUL.dtr;
    }
    double operator / (rationalNumber DIV)
    {
        return (double)ntr/dtr / (double)DIV.ntr/DIV.dtr;
    }
};

int main()
{
    rationalNumber R1, R2, R3, R4;
    int ntr,dtr;
    cout<<"Enter the numerator: ";
    cin>>ntr;
    cout<<"Enter the denominator: ";
    cin>>dtr;

    R1.assign_Val(ntr,dtr);
    R1.getValues();
    cout<<"Enter the numerator: ";
    cin>>ntr;
    cout<<"Enter the denominator: ";
    cin>>dtr;
    R2.assign_Val(ntr,dtr);
    R2.getValues();

    cout<<"The result (after Addition): "<<R1 + R2<<endl;
    cout<<"The result (after Subtraction): "<< R1 - R2<<endl;
    cout<<"The result (after Multiplication): "<< R1 * R2<<endl;
    cout<<"The result (after Division): "<< R1 / R2<<endl;
}
