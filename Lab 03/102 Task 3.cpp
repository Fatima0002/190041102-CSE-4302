#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour, minute, second;

public:
    Time()
    {
        hour=0;
        minute=0;
        second=0;
    }
    Time(int h, int m, int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    int hours()
    {
        return hour;
    }
    int minutes()
    {
        return minute;
    }
    int seconds()
    {
        return second;
    }
    void reset()
    {

            hour=0;
            minute=0;
            second=0;

    }
    void advance(int h,int m, int s)
    {
        second+=s;
        if (second>59)
        {
            minute++;
            second-=60;
        }

        minute+= m;
        if (minute>59)
        {
            hour++;
            minute-=60;
        }

        hour+=h;
        if (hour>=24)
            hour%=24;
    }

    void print()
    {
        cout <<hour<< ":" << minute<< ":" << second << "\n";
    }
};


int main()
{
    Time t1(7,15,59);
    t1.print();
    t1.advance(2, 19, 25);
    t1.print();
}
