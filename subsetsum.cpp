#include<iostream>
using namespace std;
int out[1000]={0};

void printsubsets(int n,int *a,int key,int i,int sum,int j){
    if(sum==key){
        for(int t=j-1;t>=0;t--){
            cout<<out[t]<<" ";

        }
        cout<<endl;
        return;
    }
    if(i==n){
        return;
    }

    if(sum>key){
        return;
    }

    printsubsets(n,a,key,i+1,sum,j);
    out[j]=a[i];
    sum+=a[i];
    printsubsets(n,a,key,i+1,sum,j+1);
}


int main(){
    int a[100000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int key;
    cin>>key;
    int count=0;

    printsubsets(n,a,key,0,0,0);

}
