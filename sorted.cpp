#include<iostream>
using namespace std;

bool issorted(int *a,int n)
{
    //base case
    if(n==0||n==1)
        return true;

    //assumption
    bool kyachotasortedhai=issorted(a+1,n-1);
    if(a[0]<=a[1]&&kyachotasortedhai==true){
        return true;}
        else{
            return false;
        }


}

int main()
{
    int n;
    int a[]={1,3,5,6,7,8,9};
    //cout<<"\n enter size";
    //cin>>n;
    n=sizeof(a)/sizeof(int);

    cout<<issorted(a,n);


}
