#include<bits/stdc++.h>
using namespace std;
const int size=5;

template <class T>
class my_stack
{
private:
    int top;
    T s[size];
public:
    class FULL {};
    class EMPTY {};
    my_stack()
    {
        top=-1;
    }
    void push(T n)
    {
        if(isfull())
        {
            throw FULL();
        }
        top++;
        s[top]=n;
    }
    T pop()
    {
        if(isempty())
        {
            throw EMPTY();
        }

        T temp=s[top];
        top--;
        return temp;
    }
    T peek()
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

    my_stack<int>I;
    try
    {
        I.push(1);
        I.push(2);
        I.push(3);
        I.push(4);
        I.push(5);
        I.push(6); // ->catch
        I.push(7);
        I.push(9);
    }
    catch(my_stack<int>::FULL f)
    {
        cout<<"Stack overflow"<<endl;
    }

    try
    {
        cout<<I.pop()<<endl;
    }
    catch(my_stack<int>::EMPTY e)
    {
        cout<<"Stack underflow"<<endl;
    }
    cout<<I.peek()<<endl;

}

