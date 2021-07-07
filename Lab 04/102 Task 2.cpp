#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Person
{
private:
    string EmpName;
    int ID;
    int Age;
    float Salary;
    string Status;

public:
    FeedInfo(string EmpName, int ID, int Age, int Salary)
    {
        Person::EmpName=EmpName;
        Person::ID=ID;
        Person::Age=Age;
        Person::Salary=Salary;
        getStatus();
    }

    getStatus()
    {
        if(Age<=25)
        {
            if(Salary<=20000)
            {
                Status="Low";
            }
            else
            {
                Status="Moderate";
            }
        }
        else
        {
            if(Salary<=21000)
            {
                Status="Low";
            }
            else if(Salary>21000 && Salary<=60000)
            {
                Status="Moderate";
            }
            else
            {
                Status="High";
            }
        }
    }

    ShowInfo()
    {
        cout<<"----------   ******  ----------"<<endl;
        cout<<"Name: "<<EmpName<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Age: "<<Age<<endl;
        cout<<"Salary: "<<Salary<<endl;
        cout<<Status<<" salaried person"<<endl;
        cout<<"-------------------------------\n"<<endl;
    }
};
int main()
{
    Person p1,p2;
    p1.FeedInfo("Prerana",02,26,150000);
    p1.ShowInfo();
    p2.FeedInfo("Procheta",04,17,30000);
    p2.ShowInfo();

    return 0;
}
