#include<iostream>
using namespace std;

void bsort(int arr[],int n)//bubble sort
{
    //base case
    if(n==1)
        return ;
    //recursive
    else
    {
        for(int i=0;i<n-1;i++)
        {if (arr[i]>arr[i+1])
         {
          int temp=arr[i];
          arr[i]=arr[i+1];
          arr[i+1]=temp;
          }
        }
        bsort(arr,n-1);
    }
}

void printArray(int arr[], int n) //to print the sorted array
{
    for (int i=0; i < n; i++)
        cout<<arr[i];
        cout<<endl;
}




int main()
{
    int arr[]={1,3,6,9,2,5};
    int n=sizeof(arr)/sizeof(int);
     bsort(arr,n);
    cout<<"sorted array:";
    printArray(arr,n);
    return 0;
}
