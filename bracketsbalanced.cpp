#include<iostream>
using namespace std;

char out[10000];

bool bracketsBalanced(char *in, int i, int j)
{
    //base case
    if(in[i]=='\0' && j==0)
    {
        return true;
    }

    //recursive case
    if(in[i]=='[' || in[i]=='{' || in[i]=='(')
    {
        out[j]=in[i];
        return bracketsBalanced(in,i+1,j+1);
    }
    else if(in[i]==')')
    {
        if(out[j-1]=='(')
        {
            return bracketsBalanced(in,i+1,j-1);
        }
        else
        {
            return false;
        }
    }
    else if(in[i]=='}')
    {
        if(out[j-1]=='{')
        {
            return bracketsBalanced(in,i+1,j-1);
        }
        else
        {
            return false;
        }
    }
    else if(in[i]==']')
    {
        if(out[j-1]=='[')
        {
            return bracketsBalanced(in,i+1,j-1);
        }
        else
        {
            return false;
        }
    }

        return bracketsBalanced(in,i+1,j);
}

int main()
{
    char in[10000];
    cin.getline(in,10000);
    if(bracketsBalanced(in,0,0)==true)
        cout<<"true";
    else
        cout<<"false";
}
