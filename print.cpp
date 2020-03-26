#include<iostream>
using namespace std;

void print(int*a,int n)
{
    //base case
    if(n==0)//no elements in array
        return  ;
    //assumption
  cout<<a[0]<< " "; //ascending order
  print(a+1,n-1);


  /*print(a+1,n-1);//descending order
  cout<<a[0]<< " ";*/


}

void printreverse(int*a,int n)
{
    //base case
    if(n==0)//no elements in array
        return  ;
//recursive case
cout<<a[n-1]<<" ";//descending order
printreverse(a,n-1);
}



int main()
{
    int n;
    int a[]={1,2,3,4,5};

    n=sizeof(a)/sizeof(int);

    print(a,n);
    cout<<endl;
    printreverse(a,n);

    return 0;


}
