#include<iostream>
using namespace std;

int fibo(int n)
{
    //base case
    if(n==0||n==1)
    {
        return n;
    }
    // int ans=fibo(n-1)+fibo(n-2);
    //return ans;
    return fibo(n-1)+fibo(n-2);
}
int Fibo1(int*arr,int n){  //top down approach
  if(n==0||n==1){
    arr[n]=n;
    return n;
  }

  if(arr[n]!=-1){
    return arr[n];
  }
  int ans=Fibo1(arr,n-1)+Fibo1(arr,n-2);
  arr[n]=ans;
  return arr[n];


}
int BottomUp(int n){
  int *a=new int[n+1];
  //intitialization
  a[0]=0;
  a[1]=1;
  for(int i=2;i<=n;i++){
    a[i]=a[i-1]+a[i-2];
  }
  int ans=a[n];
  delete[]a;
  return ans;

}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }

    cout<<fibo(n)<<endl;
    cout<<Fibo1(arr,n)<<endl;
    cout<<BottomUp(n)<<endl;
    return 0;
}
