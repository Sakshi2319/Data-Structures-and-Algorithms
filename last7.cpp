#include<iostream>
using namespace std;

int last7(int*a,int n,int i)
{

    //base case
    if(i==n){return -1;}//mtlb nhu mila

    if(a[i]==7){
            int maybeanschotaindex=i;
            int badaindex=last7(a,n,i+1);
    if(badaindex>maybeanschotaindex)
        return badaindex;
    else
        return maybeanschotaindex;
    }

   return last7(a,n,i+1);
}

int main()
{
    int n;
    int a[]={1,2,3,4,5,7,3,7,8};

    n=sizeof(a)/sizeof(int);
    cout<<last7(a,n,0);
    cout<<endl;



    return 0;


}
