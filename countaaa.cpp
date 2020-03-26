#include<iostream>
using namespace std;
int c1=0;
int c2=0;

void count1 (char*str,int i){
   //base case
   if(str[i]=='\0'){
      cout<<c1<<endl;
      return ;}
   //recursive case
   if(str[i]=='a'&&str[i+1]=='a' && str[i+2]=='a'){
       c1++;
       //count1(str,i+1);
   }
   count1(str,i+1);
}

void count2(char*str,int i){
    if(str[i]=='\0'){
      cout<<c2<<endl;
      return ;}
      //recursive
       if(str[i]=='a'&&str[i+1]=='a' && str[i+2]=='a'){
       c2++;
       count2(str,i+3);
       }
       else
       {
           count2(str,i+1);
       }
}


int main() {
   char str[100];
   cin>>str;
    count1(str,0);
    count2(str,0);
    return 0;
}
