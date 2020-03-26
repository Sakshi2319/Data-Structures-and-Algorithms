#include<iostream>
#include<cstring>
using namespace std;

int LCS(char*a,char*b)
{
    int dp[100][100]={0};
    int n=strlen(a);
    int m=strlen(b);
    //initialise with 0
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])//ek kam because humne already 0 daal rkha hai
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
               dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<=n;i++){  //for printing
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

 return dp[n][m];

}

int main(){
char a[100]="ade";
char b[100]="cabde";

cout<<LCS(a,b)<<endl;

return 0;
}
