



#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int j=0;
void dict(char *in,int i,string out[1000])
{
    if(in[i]=='\0')
    {
        out[j]=in;
        j++;
        return;
    }
    for(int k=i;in[k]!='\0';k++)
    {
        swap(in[i],in[k]);
        dict(in,i+1,out);
        swap(in[i],in[k]);
    }
}
int main()
{
    char in[1000];
    cin>>in;
    string out[1000];
   dict(in,0,out);
   sort(out,out+j);

    for(int i=0;i<j;i++)
    {
        if(out[i]>in)
        {
            cout<<out[i]<<endl;
        }
    }
    j=0;
	return 0;
}

