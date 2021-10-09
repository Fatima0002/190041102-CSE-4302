#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Animal
{
private:
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;
    int age;
    int birthYear;
public:
    Animal()
    {
        nameOfAnimal=" ";
        habitat_area=" ";
        sound=" ";
        weight=0;
        height=0;
        age=0;
        birthYear=2021;
    }
    void setBirthYear(int birthyear)
    {
        if(birthyear>2021)
        {
            cout<<"The birth year is invalid"<<endl;
        }
        else
        {
            Animal::birthYear = birthYear;
        }
    }
    getInformation()
    {
        cout<<"---------------Animal Information---------------"<<endl;
        cout<<"Enter the name of Animal: "<<endl;
        getnameOfAnimal();
        cout<<"Enter the Habitat area: "<<endl;
        gethabitat_area();
        cout<<"Enter Animal Sound : "<<endl;
        getsound();
        cout<<"Enter Weight: "<<endl;
        getweight();
        cout<<"Enter Height: "<<endl;
        getheight();
    }
    void setnameofAnimal(string name)
    {
        nameOfAnimal=name;
    }
    void setHabitat(string hab)
    {
        habitat_area=hab;
    }
    void setSound(string s)
    {
        sound=s;
    }
    void setWeight(int w)
    {
        weight=w;
    }
    void setHeight(int h)
    {
        height=h;
    }
    void setBYr(int byr)
    {
        birthYear=byr;
    }
    void getnameOfAnimal()
    {
        cout<<"Enter the name of Animal: "<<endl;
        cin>>nameOfAnimal;
    }
    void gethabitat_area()
    {
        cout<<"Enter the Habitat area: "<<endl;
        cin>>habitat_area;
    }
    void getweight()
    {
        cout<<"Enter Weight: "<<endl;
        cin>>weight;
    }
    void getheight()
    {
        cout<<"Enter Height: "<<endl;
        cin>>height;
    }
    void getsound()
    {
        cout<<"Enter Animal Sound : "<<endl;
        cin>>sound;
    }
    int getAge()
    {
        age=2021-birthYear;
        return age;
    }
    changeWeight(int pounds)
    {
        weight=pounds;
    }

    void vocalize()
    {
        cout<<sound<<endl;
    }
    void DisplayInfo()
    {
        cout<<"Animal Name: "<<nameOfAnimal<<endl;
        cout<<"Habitat Area: "<<habitat_area<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Height: "<<height<<endl;
        cout<<"Age :"<<getAge()<<endl;
        cout<<"Sound :";
        vocalize();
        cout<<""<<endl;
    }
    ~Animal()
    {

    }
};

class Cow:public Animal
{
public:
    string a_sound="moo";
    setSound()
    {
        a_sound="moo";
    }
    Cow()
    {
        Animal::setnameofAnimal("Red Cow");
        Animal::setHabitat("Bangladesh");
        Animal::setSound(a_sound);
    }
};
class Cow1: public Cow
{
    int meat_q;
};
class Cow2: public Cow
{
    int milk_q;
};
class Chicken:public Animal
{
public:
    string a_sound="buck buck";
    setSound()
    {
        a_sound="buck buck";
    }
    Chicken()
    {
        Animal::setnameofAnimal("Red Chicken");
        Animal::setSound(a_sound);
    }
};
class Cat:public Animal
{
public:
    string a_sound="meow";
    void setSound()
    {
        a_sound="meow";
    }
    Cat()
    {
        Animal::setnameofAnimal("Black Cat");
        Animal::setSound(a_sound);
    }
};

//////////////////////////////////////////////////////////////////////
int main()
{
    Chicken chick1;
    chick1.DisplayInfo();
    Cow c1;
    c1.setBirthYear(2015);
    c1.DisplayInfo();
    Cat cat1;
    cat1.vocalize();
    cat1.DisplayInfo();
}
