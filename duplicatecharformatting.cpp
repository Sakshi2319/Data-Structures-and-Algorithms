#include<iostream>
#include<string.h>
using namespace std;
void format(char*str, int len,int i)
{
    //base case
    if(i==len+1)
    {
        cout<<str;
        return;
    }
    //recursive
    if(str[i]==str[i+1])
    {
        for(int j=len;j>i;j--)
        {
            str[j+1]=str[j];
        }
        str[i+1]='*';
        int len=strlen(str);
    }
    format(str,len,i+1);
}
int main()
{
    char str[1000];
    cin>>str;
    int len=strlen(str);
    format(str,len,0);
}
