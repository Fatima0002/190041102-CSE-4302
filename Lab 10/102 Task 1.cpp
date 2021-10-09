#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Animal
{
protected:
    string name_Of_Animal;
    string habitat_area;
    int weight;
    int height;
    int heart_girth;
    int age;
public:
    Animal(int hg):
        heart_girth(hg) {}
    virtual void Name_and_Age(string name,int age)
    {
        cout << "Name: " <<name<< endl;
        cout << "Age: " <<age<< endl<<endl;
    }
    virtual void H_area(string h_area)
    {
        cout << "Habitat area: " <<h_area<< endl;
    }
    virtual void Weight_Calculation(int heart_girth, int body_length)
    {
//calculate body weight using the formula HEART GIRTH x HEART GIRTH x BODY LENGTH / 300 = ANIMAL WEIGHT IN POUNDS.
        weight = (heart_girth*heart_girth*body_length)/300;
        cout<<"Weight calculated = "<<weight<<endl;
    }
    virtual void display()=0;
};

class Info:public Animal
{
private:
    int body_length;
public:
    Info(int hg, int bl):Animal(hg)
    {
        heart_girth = hg;
        body_length = bl;
    }
    virtual void Weight_Calculation(int heart_girth, int body_length)
    {
//calculate body weight using the formula HEART GIRTH x HEART GIRTH x BODY LENGTH / 300 = ANIMAL WEIGHT IN POUNDS.
        cout<<"Weight calculated = "<<(heart_girth*heart_girth*body_length)/300<<endl;
    }
    void display()
    {
        cout << "Info:-Name: " << name_Of_Animal<<  endl;
        cout << "Age: "<<age << endl;
    }
};

int main()
{
    Animal *a[50];
    a[1] = new Info(70,78);
    a[1]->Name_and_Age("Cow",10);
    a[1]->Weight_Calculation(70,78);
    a[1]->display();
}
