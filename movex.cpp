
#include<iostream>
#include<cstring>
using namespace std;
void movex(char *in,int n,int i,char *out, int j)
{
	//base case
	if(in[i]=='\0')
	{
		while(j<n)
		{
		out[j]='x';
		j++;
	}
		return;
	}
	//recursive case

	if(in[i]!='x')
	{
		out[j]=in[i];
		movex(in,n,i+1,out,j+1);
	}
	else if(in[i]=='x')
	{
		movex(in,n,i+1,out,j);
	}

}
int main()
{
	char in[100],out[100];
	cin>>in;
	int n=strlen(in);
	movex(in,n,0,out,0);
	for(int i=0;i<n;i++)
	{
		cout<<out[i];
	}
}
