#include<iostream>
using namespace std;

int multiply(int x,int y)
{
  //base case
  if(y==0)
       {
           return 0;
       }
  //recursive
  else
  { return x+multiply(x,y-1);
  }
}

int main()
{
    int x,y;
    cout<<"enter nos";
    cin>>x>>y;
    cout<<multiply(x,y);

    return 0 ;
}
