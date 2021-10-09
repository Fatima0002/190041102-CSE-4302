#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10];
    set<int>S;
    for(int i=0;i<20;i++)
    {
        if(i%2 == 1)
            S.insert(i);
        else
            arr[i/2]=i;

    }

    vector<int>V(20);
    merge(arr,arr+10,S.begin(),S.end(),V.begin());
     for (auto i = V.begin(); i != V.end(); ++i)
        cout << *i << " ";

    return 0;
}

