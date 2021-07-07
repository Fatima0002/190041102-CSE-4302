#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

class BankAccount
{
private :
    int acc_num;
    string holder_name;
    bool acc_type; //(current/savings)
    double curr_balance;
    double min_balance;

public:

    void assign(int acc_num,string holder_name,double curr_balance,double min_balance)
    {
        BankAccount::acc_num=acc_num;
        BankAccount::holder_name=holder_name;
        BankAccount::curr_balance=curr_balance;
        BankAccount::min_balance=min_balance;
    }
    double showBalance()
    {
        cout<<"Current balance is= "<<curr_balance<<endl<<endl;
    }
    void deposit(double a)
    {
        curr_balance += a;
    }
    void withdrawal(double a)
    {
        if(curr_balance-a>=10000)
        {
            curr_balance -= a;
        cout<<"after withdrawing "<<a<<endl;
        }
        else
        {
            curr_balance=curr_balance;
            cout<<"Withdrawal rejected"<<endl;
        }
    }
    void giveInterest(double rate=3)
    {
        float interest = (curr_balance*rate/100);
        curr_balance=curr_balance+interest-(interest*10/100);
    }
    ~BankAccount()
    {
        cout<<":  Account of Mr."<<holder_name<<" with account no "<<acc_num<<" is destroyed with a balance BDT "<<curr_balance<<endl;
    }
};

int main()
{
    BankAccount b1,b2;
    b1.assign(1285459625,"Muhammad", 250000, 10000);
    b1.showBalance();
    b1.giveInterest();
    b1.showBalance();
    b1.withdrawal(270000);
    b1.showBalance();
    b1.withdrawal(2000);
    b1.showBalance();

    return 0;
}
