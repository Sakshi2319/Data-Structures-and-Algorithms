#include<iostream>
using namespace std;
int elephantways(int n,int m){
//base case
if(n==0&&m==0)
    return 1;

    if(n<0||m<0)
    return 0;
int sumrow=0,sumcol=0;
//recursive case
for(int k=1;k<=m;k++)
    sumrow+=elephantways(m-k,n);

        for(int k=1;k<=n;k++)
    sumcol+=elephantways(m,n-k);


return sumrow+sumcol;

}



int main()
{
    int n,m;
    cin>>n>>m;
    cout<<elephantways(n-1,m-1)<<endl;
}
