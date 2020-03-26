#include<iostream>
using namespace std;

 int* createarray(int n){
    int *a=new int[n];
          for(int i=0;i<n;i++){
            a[i]=i;
           }
  return a;
}

int main()
{
    //int *a==new int;
    //*a=10;
    int n;
    cin>>n;
       int *arr=createarray(n);  //int *arr=new int[n];

    for(int i=0;i<n;i++)
        arr[i]=i;
    cout<<endl;

     for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
       cout<<endl;
       //delete []arr;

       int *a=new int;
       //cout<<*a;



}
