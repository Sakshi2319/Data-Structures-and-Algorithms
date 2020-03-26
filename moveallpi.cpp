#include<iostream>
#include<cstring>
using namespace std;

void replacepi(char *in,char *out,int n,int i,int j){
	// base case
	if(i==n){
		out[j]='\0';
		return;
	}
	// recursive case
	if(in[i]=='p' && in[i+1]=='i'){
		out[j]='3';
		out[j+1]='.';
		out[j+2]='1';
		out[j+3]='4';
		replacepi(in,out,n,i+2,j+4);
	}
	else{
		out[j]=in[i];
		replacepi(in,out,n,i+1,j+1);
	}
}


int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
	char in[1000];
	cin>>in;
	char out[1000];
	int n1=strlen(in);
	replacepi(in,out,n1,0,0);
	cout<<out<<endl;
}
return 0;

}
