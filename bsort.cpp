#include<iostream>
using namespace std;

void bsort(int *arr,int n,int i,int k)//bubble sort
{
    //base case
    if(i==n-1)
        return ;
    //recursive
    else
    {
        if(k==n-1)
        {
            bsort(arr,n,i+1,0);

        }
        else{
            if(arr[k]>arr[k+1])
                swap(arr[k],arr[k+1]);
        }

        bsort(arr,n,i,k+1);
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
     bsort(arr,n,0,0);
    cout<<"sorted array:";
    printArray(arr,n);
    return 0;
}
