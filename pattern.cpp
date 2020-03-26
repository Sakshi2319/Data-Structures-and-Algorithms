#include<iostream>
using namespace std;
void printrow(int x)
{
    //base case
    if(x==0)
    return;
    //recursive
    cout<<"*"<<'\t';
    printrow(x-1);
}

void pyramid(int i,int n)
{
    //base case
    if(n==0)
    return;
    //recursive
    printrow(i);
    cout<<endl;
        pyramid(i+1,n-1);

}


int main () {
    int n;
    cin>>n;
    pyramid(1,n);
	return 0;
}

