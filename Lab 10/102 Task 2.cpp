#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Patient
{
protected:
    string name;
    int health;
    int oxygen_level;
public:
    Patient() {}
    Patient(string n,int h,int o_l):
        name(n),health(h),oxygen_level(o_l) {}
    Patient operator = (Patient &source)
    {
        health=source.health;
        oxygen_level=source.oxygen_level;
        return Patient(name,health,oxygen_level);
    }
    Patient(const Patient &source):
        health(source.health),oxygen_level(source.oxygen_level)
    {
    }
    void display()
    {
        cout<<"-----------Patient Info---------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"Oxygen Level(%): "<<oxygen_level<<endl<<endl;;
    }
    void setName(string s)
    {
        name=s;
    }
};
int main()
{
    Patient pat1("Sarah",100,90);
    pat1.display();
    Patient pat2("Alishba",250,85);
    pat1 = pat2;
    pat1.setName("Dahlia");
    pat1.display();
    pat2.display();
}

