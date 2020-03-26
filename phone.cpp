#include<iostream>
using namespace std;
int count=0;
string str[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void phonekeypad(char in[] ,char out[] ,int i,int j)
{
    //base case
    if(in[i]=='\0'){
      out[j]='\0';
        cout<<out<<" ";
        count++;
          return;
    }


    //recursive
    int digit=in[i]-'0';
    for(int k=0;str[digit][k]!=0;k++){
    out[j]=str[digit][k];
    phonekeypad(in,out,i+1,j+1);}

}


int main() {
    char in[10],out[100];
    cin>>in;
    phonekeypad(in,out,0,0);
    cout<<endl;
    cout<<count;
    return 0;
}
