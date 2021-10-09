#include <iostream>
#include<bits/stdc++.h>
using namespace std;


 template<class N>
 N amax(N *a,int size,int n)
 {
    sort(a,a+size,greater<int>());
    return a[n-1];
 }
 int main()
 {
     int arr[]={1,2,3,4,5};
     cout<<amax(arr,4,3)<<endl;

     double darr[]={1.2,1.5,2.5,4.5};
     cout<<amax(darr,5,1)<<endl;

     char carr[]={'a','b','c'};
     cout<<amax(carr,3,2);
 }

