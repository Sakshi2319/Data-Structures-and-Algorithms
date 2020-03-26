#include<iostream>
using namespace std;

int ways(int n,int m){
//base case
if(n==0&&m==0)
    return 1;
if(n<0||m<0){//negative index na chala jaaye
    return 0;
}


//recursive
return ways(n-1,m)+ways(n,m-1);

}

int main()
{
    int n,m;
    cin>>n>>m;
    cout<<ways(n,m)<<endl;
}
