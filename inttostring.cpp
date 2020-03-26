#include<iostream>
using namespace std;

 void inttostring( string s[] ,int n)
 {
     //base case
     if(n==0)
        return;
     //recursion

     int digit=n%10;
     inttostring(s,n/10);
     cout<<s[digit]<<" ";

 }



 int main()
 {
     int n;
     string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
     cout<<"enter number";
     cin>>n;
     inttostring(s,n);

     return 0;



 }
