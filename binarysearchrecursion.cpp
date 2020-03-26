#include<iostream>
using namespace std;
int  bsearch (int arr[],int num,int i,int n)//this is returning index of the searched element
{
  //base case
  if(i>n)
    return -1;


  int mid=(i+n)/2;
  if(arr[mid]==num)
        return mid;
   else if(arr[mid]>num)
    { int keykaindex = bsearch(arr,num,i,mid-1);
    return keykaindex;}
    else
      {return bsearch(arr,num,mid+1,n);}

}

int main()
{
    int arr[]={1,3,5,7,9};//considering a sorted array we find the number
    int n=sizeof(arr)/sizeof(int);
    int num;
    cout<<"enter no to be searched ";
    cin>>num;
    cout<<bsearch(arr,num,0,n);
   return 0;

}
