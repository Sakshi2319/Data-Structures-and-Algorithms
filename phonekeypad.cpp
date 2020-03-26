#include<iostream>
using namespace std;


string keys[10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};//mapping of characters

void phonekeypad(char in[],int i,char out[],int j){
//nase case
if(in[i]=='\0'){
    out[j]='\0';
cout<<out<<endl;
return ;
}



//recursive case
int digit=in[i]-'0';
for(int k=0;keys[digit][k]!='\0';k++)
{
    out[j]=keys[digit][k];
    phonekeypad(in,i+1,out,j+1);
}
}



int main()
{
    char in[10],out[100];
    cin>>in;
    phonekeypad(in,0,out,0);

   return 0;
}
