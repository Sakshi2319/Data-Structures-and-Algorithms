#include<iostream>
#include<cstring>
using namespace std;
void format(char*str,int i)
{
    //base case
    if(i==strlen(str))
    {
        return;
    }
    //recursive
    if(str[i]==str[i+1])
    {
        for(int j=strlen(str);j>i;j--)
        {
            str[j]=str[j-1];
        }
        str[i+1]='*';
    }
    format(str,i+1);
    return;
}
int main()
{
    char str[10000];
    cin>>str;
    format(str,0);
    cout<<str;
    return 0;
}
