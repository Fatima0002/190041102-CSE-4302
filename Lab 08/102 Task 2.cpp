#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Seat
{
/* Private members cannot be inherited by the inherited derived class, So we have the data members protected
so that if we inherit public its accessed publicly. */
protected:
    string comfortablity;
    bool seat_warmer;
public:
    Seat()
// constructor to initialize the data members
    {
        comfortablity=" ";
        seat_warmer=false;
    }
    //getter and setter functions, set sets the value for the data member and set prints those values
    void setSeat(string comfortablity, bool seat)
    {
        this->comfortablity=comfortablity;
        seat_warmer=seat;
    }
    void get_Seat()
    {
        cout<<"The seat is :"<<comfortablity<<endl;
        if(seat_warmer)
        {
            cout<<"The seat is warm"<<endl;
        }
        else
        {
            cout<<"The seat is not warm"<<endl;
        }
    }
    //destructor for deinitialize the data members to save memory
    ~Seat()
    {

    }
};

class Wheel
{
protected:
    double Circumferance;
public:

    Wheel()
    {
        Circumferance=0;
    }
    /* in this set function we are passing the parameter while in some other set function
    we are taking the input right into the function */
    void setCircumferance(double c)
    {
        Circumferance=c;
    }
    double get_Circumferance()
    {
        cout<<"The circumference of the wheel is: "<<Circumferance<<endl;
    }
    ~Wheel()
    {

    }

};
class Engine
{
    /*
    The class Engine stores information about
    the Maximum Fuel Consumption Rate, Maximum Energy Production Rate, Average RPM.
    */
protected:
    int max_fuel;
    int consum_rate;
    int max_energy;
    int production_rate;
    int RPM;
public:
    Engine()
    {
        max_fuel=0;
        consum_rate=0;
        max_energy=0;
        production_rate=0;
        RPM=0;
    }
    void setValue()
    {
        cout<<"Enter value of Maximum Fuel: ";
        set_max_fuel();
        cout<<"Enter Consumption Rate :";
        set_consumption_rate();
        cout<<"Enter Maximmum Energy Rate: ";
        set_max_energy();
        cout<<"Enter Production Rate: ";
        set_production_rate();
        cout<<"Enter RPM :";
        set_RPM();
    }
    void set_max_fuel()
    {
        cin>>max_fuel;
    }
    int get_max_fuel()
    {
        return max_fuel;
    }
    void set_consumption_rate()
    {
        cin>>consum_rate;
    }
    int get_consum_rate()
    {
        return consum_rate;
    }
    void set_max_energy()
    {
        cin>>max_energy;
    }
    int get_max_energy()
    {
        return max_energy;
    }
    void set_production_rate()
    {
        cin>>production_rate;
    }
    int get_production_rate()
    {
        return production_rate;
    }
    void set_RPM()
    {
        cin>>RPM;
    }
    int get_RPM()
    {
        return RPM;
    }
    void get_Engine_value()
    {
        cout<<"Value of Maximum Fuel: "<<get_max_fuel()<<endl;

        cout<<"Consumption Rate :"<<get_consum_rate()<<endl;
        cout<<"Maximum Energy Rate: "<<get_max_energy()<<endl;
        cout<<"Production Rate: "<<get_production_rate()<<endl;
        cout<<"RPM :"<<get_RPM()<<endl;

    }

};

class Door
{
protected:
    string opening_mode;
public:
    Door()
    {
        opening_mode=" ";

    }
    void setDoor(string opening_mode)
    {
        this->opening_mode=opening_mode;
    }
    string get_Door()
    {
        return opening_mode;
    }
    ~Door()
    {
    }
};
//star inheritance. one derived class inherits from multiple base classes
class Car:public Seat, public Wheel, public Engine, public Door
{
    /*
    Create a Car class which consists of
    seats, wheels, engine, doors.
    Car Class also has the attribute the maximum_acceleration, fuel_capacity.
    */
private:
    int seats;
    int wheels;
    int engine;
    int doors;
    int maximum_accelration;
    int fuel_capacity;
public:
    Car()
    {
        seats=0;
        wheels=0;
        engine=0;
        doors=0;
        maximum_accelration=0;
        fuel_capacity=0;
    }
    void set_seat()
    {
        cin>>seats;
    }
    int get_seat()
    {
        return seats;
    }
    void set_wheels()
    {
        cin>>wheels;
    }
    int get_wheels()
    {
        return wheels;
    }
    void set_engine()
    {
        cin>>engine;
    }
    int get_engine()
    {
        return engine;
    }
    void set_doors()
    {
        cin>>doors;
    }
    int get_doors()
    {
        return doors;
    }
    void set_max_acc()
    {
        cin>>maximum_accelration;
    }
    int get_max_acc()
    {
        return maximum_accelration;
    }
    void set_fuel()
    {
        cin>>fuel_capacity;
    }
    int get_fuel()
    {
        return fuel_capacity;
    }
    void set_Info()
    {
        cout<<"Enter Seats: ";
        set_seat();
        cout<<"Enter Wheels: ";
        set_wheels();
        cout<<"Enter Engine Type: ";
        set_engine();
        cout<<"Enter Door Number :";
        set_doors();
        cout<<"Enter Maximum Acceleration: ";
        set_max_acc();
        cout<<"Enter Fuel Capacity :";
        set_fuel();
    }
    void get_Info()
    {
        // in this derived function we are accessing the functions of the base class which has been inherited
        cout<<"Seats: "<<get_seat()<<endl;
        cout<<"Wheels: "<<get_wheels()<<endl;
        cout<<"Engine Type: "<<get_engine()<<endl;
        cout<<"Door Number :"<<get_doors()<<endl;
        cout<<"Maximum Acceleration: "<<get_max_acc()<<endl;
        cout<<"Fuel Capacity :"<<get_fuel()<<endl;
        cout<<endl;
        get_Seat();
        cout<<endl;
        cout<<"Circumference of the wheel of the car is :"<<get_Circumferance();
        cout<<endl;
        cout<<"The type of door is: "<<get_Door();
        cout<<endl;
        get_Engine_value();
        cout<<endl;
    }
    ~Car()
    {
    }
};
int main()
{
    Car car;
    car.set_Info();
    car.setCircumferance(23.05);
    cout<<"Enter Door type? 1.Yes/2.No";
    int op;
    cin>>op;
    if(op==1)
    {
        string str;
        cin>>str;
        car.setDoor(str);
    }
    else
    {
        car.setDoor("sideways");
    }
    car.setValue();
    cout<<"Enter Seat Comfortability? 1.Yes /2.No";
    cin>>op;
    string str;
    str="Pleasant";
    if(op==1)
    {
        cin>>str;
    }
    cout<<"Enter Seat Warm or not? 1.Yes / 2.No";
    cin>>op;
    if(op==1)
    {
        car.setSeat(str,true);
    }
    else
    {
        car.setSeat("Pleasant",false);
    }
    car.get_Info();
}
