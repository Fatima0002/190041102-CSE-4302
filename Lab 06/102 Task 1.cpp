#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class Counter
{
private:
    int count;
    int increament_step;

public:
    int val;
    Counter()
    {
        increament_step=1;
        count=0;
    }
    void setIncrementStep(int step_val)
    {
        increament_step = step_val;
    }
    int getCount()
    {
        return count;
    }
    void increment()
    {
        count+= increament_step;
    }
    void resetCount()
    {
        count= 0;
    }
    Counter operator +(Counter cnt)
    {
        Counter temp;
        temp.count=temp.count+cnt.count;
        temp.increament_step=min(temp.increament_step,cnt.increament_step);
        return temp;
    }
    Counter operator +(int )
    {
        Counter temp;
        temp.count=temp.count+val;
        return temp;
    }
    Counter operator +=(Counter cnt)
    {
        Counter temp;
        temp.count+= cnt.count;
        temp.increament_step+= cnt.increament_step;
        return temp;
    }

    Counter operator ++ ()
    {
        ++count;
        Counter temp;
        temp.count = count;
        return temp;
    }
    Counter operator ++(int)
    {
        count++;
        Counter temp;
        temp.count= count;
        return temp;
    }
};
int main()
{
    Counter c1;
    c1.setIncrementStep(5);
    c1.increment();

    Counter c2;
    c2.setIncrementStep(6);
    c2.increment();

    Counter c3;
    c3=c1+c2;
    cout<<c3.getCount()<<endl;

    int val=c1.val;
    c1=c2+val;
    cout<<c1.getCount()<<endl;
    c1+=c2;
    cout<<c1.getCount()<<endl;
    c1=c2++;
    cout<<c1.getCount()<<endl;
    c1=++c2;
    cout<<c1.getCount()<<endl;
}
