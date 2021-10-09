#include<bits/stdc++.h>
using namespace std;

const int size=50;

template <class T>
class my_stack
{
private:
    int top;
    T s[size];
public:
    my_stack()
    {
        top=-1;
    }
    void push(T n)
    {
        if(isfull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        top++;
        s[top]=n;
    }
    T pop()
    {
        if(isempty())
        {
            cout<<"underflow"<<endl;
        }
        T temp=s[top];
        top--;
        return temp;
    }
    T peek() //top
    {
        return s[top];
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        return false;
    }
    bool isfull()
    {
        if(top==(size-1))
            return true;
        return false;
    }
};

int main()
{
    my_stack<float>F;
    F.push(1.2);
    F.push(2.3);
    F.push(3.4);
    F.push(4.5);
    F.push(5.6);

    cout<<F.pop()<<endl;
    cout<<F.peek()<<endl;

    my_stack<int>I;
    I.push(1);
    I.push(2);
    I.push(4);
    I.push(5);

    cout<<I.pop()<<endl;
    cout<<I.peek();

}
