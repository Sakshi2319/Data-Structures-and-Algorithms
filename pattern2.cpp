#include<iostream>
using namespace std;

void printrow(int x)
{
    if(x==0)
    return;

       cout<<"*"<<'\t';
      printrow(x-1);


}


void print (int i,int n)
{
    //base case
    if(n==0)
    return;
    //recursive
    printrow(n);
    cout<<endl;
    print(i+1,n-1);

}

int main() {
    int n;
    cin>>n;
    print(1,n);
    return 0;
}
