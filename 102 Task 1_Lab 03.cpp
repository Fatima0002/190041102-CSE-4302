#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class RationalNumber
{
private:
    int numerator;
    int denominator;

public:
    void assign(int numerator,int denominator)
    {
        if(denominator==0)
        {
            cout<<"Error : Undefined input"<<endl;
            return;
        }
        RationalNumber::numerator=numerator;
        RationalNumber::denominator=denominator;
    }
    double convert()
    {
        double n=numerator,d=denominator,res;
        res=n/d;
        return res;
    }
    void invert()
    {
        if(numerator==0)
        {
            cout<<"Error : Undefined input"<<endl;
            return;
        }
        swap(numerator,denominator);
    }
    void print()
    {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }
};


int main()
{
    RationalNumber R;
    int Ntr,Dtr;
    cin>>Ntr;
    cout<<"/"<<endl;
    cin>>Dtr;
    R.assign(Ntr,Dtr);
    R.print();
    cout<<"which equals  "<<R.convert()<<endl;
    R.invert();
    cout<<"\nInverting the number: "<<endl;
    R.print();
    cout<<"which equals  "<<R.convert()<<endl;
}
