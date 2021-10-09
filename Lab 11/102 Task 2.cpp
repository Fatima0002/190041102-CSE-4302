#include<fstream>
#include<iostream>
#include<typeinfo>

using namespace std;
#include<process.h>

const int LEN=50;

enum person_type {temployee,tcustomer};

class shop_ptype
{
private:
    char Person_name[LEN];
    int ID;
    static int n; //current no of persons;
    static shop_ptype* arrap[]; //array of ptrs to persons;

public:
    virtual void getdata()
    {
        cin.ignore(10,'\n');
        cout<<"Enter Name: ";
        cin>>Person_name;
        cout<<"Enter ID: ";
        cin>>ID;

    }
    virtual void putdata()
    {
        cout<<"\n Name: "<<Person_name;
        cout<<"\n ID: "<<ID;
    }
    virtual person_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
};
int shop_ptype::n;
shop_ptype* shop_ptype::arrap[100];

class employee:public shop_ptype
{
private:
    char shift[20];
    float salary;
    char type[10];

public:
    void getdata()
    {
        shop_ptype::getdata();
        cout<<"Enter shift: ";
        cin>>shift;
        cout<<"Enter salary: ";
        cin>>salary;
        cout<<"Enter type of employee: ";
        cin>>type;
    }
    void putdata()
    {
        shop_ptype::putdata();
        cout<<"\nShift: "<<shift;
        cout<<"\nSalary: "<<salary;
        cout<<"\nType: "<<type;
    }
};
class customer:public shop_ptype
{



};

void shop_ptype::add()
{
    char ch;
    cout<<"'1' to add employee\n'2' to add customer";
    cout<<"\nEnter choice:";
    cin>>ch;
    switch(ch)
    {
    case'1':arrap[n]=new employee;
            break;
    case'2':arrap[n]=new customer;
            break;
    default:
        cout<<"Unknown\n";
        return;

    }
    arrap[n++]->getdata();
}
void shop_ptype::display()
{
    for(int j=0; j<n; j++)
    {
        cout<<"---------------***-----------------"<<endl;
        cout<<(j+1);
        switch(arrap[j]->get_type())
        {
        case temployee:
            cout<<" Type: Employee";
            break;
        case tcustomer:
            cout<<" Type: Customer";
            break;
        default:
            cout<<"Unknown";
        }
        arrap[j]->putdata();
        cout<<endl;
        cout<<"---------------***-----------------"<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

    }
}

person_type shop_ptype::get_type()
{
    if(typeid(*this)==typeid(employee))
        return temployee;
    else if(typeid(*this)==typeid(customer))
        return tcustomer;
    else
    {
        cerr<<"\nWrong Person type";
        exit(1);
        return temployee;
    }
}

void shop_ptype::write()
{
    int sz;
    cout<<"Writing "<<n<<" persons.\n";
    ofstream of;
    person_type pt;
    of.open("Shop_ptype.DAT",ios::trunc|ios::binary);
    if(!of)
    {
        cout<<"\nCan't open the file\n";
        return;
    }
    for(int j=0; j<n; j++)
    {
        pt=arrap[j]->get_type();
        of.write((char*)&pt,sizeof(pt));
        switch(pt)
        {
        case temployee:
            sz=sizeof(employee);
            break;
        case tcustomer:
            sz=sizeof(customer);
            break;
        }
        of.write((char*)(arrap[j]),sz);
        if(!of)
        {
            cout<<"\nCan't write on the file\n";
            return;
        }
    }
}

void shop_ptype::read()
{
    int sz;
    person_type pt;
    ifstream in;
    in.open("Shop_ptype.DAT",ios::binary);
    if(!in)
    {
        cout<<"\nCan't open file\n";
        return;
    }
    n=0;
    while(true)
    {
        in.read((char*)&pt,sizeof(pt));
        if(in.eof())
            break;
        if(!in)
        {
            cout<<"\nCan't read\n";
            return;
        }
        switch(pt)
        {
        case temployee:
            arrap[n]=new employee;
            sz=sizeof(employee);
            break;
        case tcustomer:
            arrap[n]=new customer;
            sz=sizeof(customer);
            break;
        default:
            cout<<"\nUnknown\n";
            return;

        }
        in.read((char*)arrap[n],sz);
        if(!in)
        {
            cout<<"\nCan't read the file\n";
            return;
        }
        n++;
    }
    cout<<"\nReading "<<n<<" shop_ptype\n";

}

int main()
{
    char ch;
    while(true)
    {
        cout << "'a'--add data for a person"
             "\n' d'--display data for all persons"
             "\n' w'--write all persons data to file"
             "\n' r'--read all persons data from file"
             "\n' x'--exit"
             "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a':
            shop_ptype::add();
            break;
        case 'd':
            shop_ptype::display();
            break;
        case 'w':
            shop_ptype::write();
            break;
        case 'r':
            shop_ptype::read();
            break;
        case 'x':
            exit(0); //exit program
        default:
            cout << "\nUnknown command";

        }
    }
}

