#include<iostream>
using namespace std;

bool check7(int*a,int n,int i)
{

    //base case
    if(i==n){return false;}

    if(a[i]==7){
        return true;
    }

    return check7(a,n,i+1);

/*bool kyachotearraymeinhai=check7(a,n,i+1);
if(kyachotearraymeinhai)
{
    return true;

}
else{return false;}*/


}

int main()
{
    int n;
    int a[]={1,2,3,4,5,7};

    n=sizeof(a)/sizeof(int);
    cout<<check7(a,n,0);
    cout<<endl;



    return 0;


}
