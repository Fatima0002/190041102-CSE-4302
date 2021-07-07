#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Medicine
{
private:
    string name;
    string genericName;
    double discountPercent;
    double unitPrice;

public:
    void assignName(char name[], char genericName[])
    {
        Medicine::name=name;
        Medicine::genericName=genericName;
    }
    void assigndiscountprince()
    {
        discountPercent=0.05;
        unitPrice=0;
    }
    void assingnPrice(double price)
    {
        if (price>-1)
            unitPrice=price;
        else
            cout << "Price must be non-negative.\n";
    }
    void setDiscountPercent(double percent)
    {
        if (percent>=0 && percent<=0.45)
            discountPercent=percent;
        else
            cout<<"Discount percentage must be between 0 to 45%\n";
    }
    double getSellingPrice(int nos)
    {
        int d=unitPrice*discountPercent/100;
        unitPrice=unitPrice-d;
        return unitPrice*nos;
    }
    void print()
    {
        cout<<name<<" ("<<genericName<<") has a unit price of BDT "<<unitPrice<<". Current discount "<<discountPercent<<"%"<<endl;
    }
};

int main()
{
    class Medicine M;
    char n[100]="Napa";
    char gN[100]="Paracetamol";
    M.assignName(n,gN);
    M.assingnPrice(0.80);
    M.setDiscountPercent(0.30);
    cout<<M.getSellingPrice(1)<<'\n';
    M.print();
    return 0;
}
