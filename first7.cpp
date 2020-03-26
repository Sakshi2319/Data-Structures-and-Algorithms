#include<iostream>
using namespace std;

int first7(int*a,int n,int i)
{

    //base case
    if(i==n){return -1;}//mtlb nhi mila pure array mein

    if(a[i]==7){
        return i;
    }

   return first7(a,n,i+1);
}

int main()
{
    int n;
    int a[]={1,2,3,4,5,7};

    n=sizeof(a)/sizeof(int);
    cout<<first7(a,n,0);
    cout<<endl;



    return 0;


}
