#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void subset(string str,int index=0,string curr=""){
int n=str.length();
//base case
if(index==n){
    cout<<curr<<endl;
    return;
}
//recursive
subset(str,index+1,curr+str[index]);//ek baar consider kro ek baar nahi
subset(str,index+1,curr);

}


int main(){
string str="abc";
subset(str);
return 0;

}
