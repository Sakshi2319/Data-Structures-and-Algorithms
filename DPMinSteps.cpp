//min steps to one
#include<iostream>
#include<climits>
using namespace std;

int MinSteps(int n){
    //base case
    if(n==1)
       return 0;

    //recursive
   int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
   op1=1+MinSteps(n-1);
   if(n%2==0){
    op2=1+MinSteps(n/2);
   }
   if(n%3==0){
    op3=1+MinSteps(n/3);
   }
   return min(op1,(op2,op3));

}

int Topdown(int *arr,int n){
    //base case
    if(n==1){
       arr[n]=0;
       return 0;
    }
    //topdown mein checking if the ans already exists
    if(arr[n]!=-1){
        return arr[n];
    }

   int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;

   op1=1+Topdown(arr,n-1);
   if(n%2==0){
    op2=1+Topdown(arr,n/2);
   }
   if(n%3==0){
    op3=1+Topdown(arr,n/3);
   }
   arr[n]=min(op1,min(op2,op3));
   return arr[n];

}

int BottomUp(int n){
  int *a=new int[n+1];
  a[1]=0; //initialization
  int op1,op2,op3;
  for(int i=2;i<=n;i++){
    op1=op2=op3=INT_MAX;
    op1=1+a[i-1];
    if(i%2==0){
        op2=1+a[i/2];
    }
    if(i%3==0){
        op3=1+a[i/3];
    }
    a[i]=min(op1,min(op2,op3));
  }
  for(int i=1;i<=n;i++){
    cout<<a[i]<<" ";
    }
    cout<<endl;
    int ans=a[n];
    delete []a;
    return ans;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=1;i<=n;i++){
        arr[i]=-1;
    }

     cout<<MinSteps(n)<<endl;
    cout<<Topdown(arr,n)<<endl;
    cout<<BottomUp(n)<<endl;


    return 0;
}
