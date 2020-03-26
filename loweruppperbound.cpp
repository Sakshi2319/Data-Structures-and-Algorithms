#include<iostream>
using namespace std;
int count=0;
void occurence(int arr[],int keys[],int n,int j,int i,int k){

if(i==n)
       {
         cout<<-1<<" " <<-1;
       }
    //base case
    if(count==2 || i==n)
    {
        count=0;
        return;
    }
    //recursive
    if((arr[i]==keys[j])&& i!=-1){
        cout<<i<<" ";
        count++;
        i=-1;
        k=n-1;
         }
    else if(i!=-1)
       {
         i++;
         k=-1;
       }

        if((arr[k]==keys[j])&& k!=-1){
        cout<<k<<" ";
        count++;
        k=-1;
         }
    else if(k!=-1)
       {
            k--;
       }

occurence(arr,keys,n,j,i,k);

}



int main() {
    int n,temp;
    cin>>n;
    int arr[100],keys[100];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int no;
    cin>>no;
    for(int j=0;j<no;j++){

    cin>>keys[j];
    cin.ignore(5,'\n');

    }
     for(int j=0;j<no;j++){
    occurence(arr,keys,n,j,0,n-1);
    cout<<endl;}
return 0;
}
