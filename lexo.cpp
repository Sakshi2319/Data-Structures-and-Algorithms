#include<iostream>
using namespace std;

void Lexo(int i, int n)
{
  if(i <= n){
    cout<<i<<" ";
  }
  for(int j = 0; j <= 9; j ++)
  {
    if(i+j <= n)
    {
     Lexo(10*i+j,n);
    }
  }
}

int main()
{
  int n;
  cin>>n;
  cout<<0<<" ";
  for(int i = 1 ; i <=9 ; i++){
      Lexo(i,n);
  }
  return 0;

}
