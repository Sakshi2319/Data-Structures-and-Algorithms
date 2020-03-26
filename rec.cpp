#include<iostream>
using namespace std;

int fact(int n){
//base case
if(n==0){
    return 1;
}
//assumption , bas chalega dont think much
int chotaans=fact(n-1);
int badaans=n*chotaans;
return badaans;

}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    cout<<endl;
    return 0;
}
