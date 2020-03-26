#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int k=0;
void subsequences(char *in, int i, char *out, int j, string ans[])
{
	//base case
	if(in[i]=='\0')
	{
		out[j]='\0';
		ans[k]=out;
		k++;
		return;
	}
	//recursive case
	////dont copy
	subsequences(in,i+1,out,j, ans);
	////copy
	out[j]=in[i];
	subsequences(in,i+1,out,j+1, ans);
}
int main()
{
	char in[20];	char out[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>in;

    string ans[100];
	subsequences(in,0,out,0,ans);
	//int num=pow(2,len);

	sort(ans,ans+k);
	for(int i=0;i<k;i++)
	{
		cout<<ans[i]<<endl;
	}
}

	return 0;
}
