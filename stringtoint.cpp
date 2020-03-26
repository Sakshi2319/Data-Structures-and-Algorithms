#include<iostream>
#include<string.h>
using namespace std;
 int stringtoint(char str[],int l)
 {
     //base case
     if(l==0)
        return 0;
        //recursive
        int lastdigit=str[l-1]-'0';//char minus char is integer
        int ans=10*stringtoint(str,l-1)+lastdigit;
        return ans;
 }


 int main()
 {
     char str[20];
     cout<<"\n enter string";
     gets(str);
     int l=strlen(str);
     cout<<stringtoint(str,l);
 }
