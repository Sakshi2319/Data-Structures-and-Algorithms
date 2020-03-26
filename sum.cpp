#include<iostream>
using namespace std;
//iterative method

int sum1(int*a,int n,int i)
{
    //base case
    if(i==n)
        return 0;
    //assumption
    int chotaans=sum1(a,n,i+1);
    int badaans=a[i]+chotaans;
    return badaans;


}

int sum2(int*a,int n,int i)//i ab n se start hoga
{
    //base case
    if(i==0)
        return 0;

    //recursive case
    int chotaans =sum2(a,n,i-1);
    int badaans=a[i-1]+chotaans;
}



int main()
{
    int n;
    int a[]={1,2,3,4,5};

    n=sizeof(a)/sizeof(int);
    cout<<sum1(a,n,0);
    cout<<endl;
    cout<<sum2(a,n,n);

    return 0;


}

