#include<iostream>
using namespace std;
int i;

void print(int*a,int n)
{
    //base case
    if(n==0)//no elements in array
        return  ;
    //assumption
   if(i%2!=0)
   { if(n%2==0)
     cout<<a[1]<<endl;//case for sayn=6
     print(a+1,n-1);
   }
   else if(i%2==0)
   {
       if(n%2==0)
     cout<<a[0]<<endl; //case for say n=5
     print(a+1,n-1);
   }

                           //ascending order print(a+1,n-1);
}


void printreverse(int*a,int n)
{
    //base case
    if(n==0)//no elements in array
        return  ;
//recursive case
if(n%2!=0)
{ cout<<a[n-1]<<endl;}
  //descending order
    printreverse(a,n-1);
}



int main ()
{
    int n;
    cin>>n;
    int a[100];
    a[0]=1;
    for( i=1;i<n;i++)
    { a[i]=i+1;}
      i=n-1;
      printreverse(a,n);
      print(a,n);
    return 0;


}

