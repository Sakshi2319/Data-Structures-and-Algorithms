#include<iostream>
using namespace std;

int sum(int*a,int n)
{
    //base case
    if(n==0)
        return 0;
    //assumption
    int chotasum=sum(a+1,n-1);
    return a[0]+chotasum;


}
int main()
{
    int n;
    int a[]={1,2,3,4,5};

    n=sizeof(a)/sizeof(int);

    cout<<sum(a,n);
    return 0;


}
