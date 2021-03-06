#include<iostream>
using namespace std;

int MinCost(int cost[][4],int i,int j,int dp[][100]){
    int ans;
    //chaeckkkk
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==0&&j==0){
            dp[i][j]=cost[i][j];
        return cost[i][j];
    }
    else if(i==0&&j>0){
        int ans=MinCost(cost,i,j-1,dp)+cost[i][j];
       dp[i][j]=ans;
       return ans;
    }
    else if(i>0 && j==0){
        int ans=MinCost(cost,i-1,j,dp)+cost[i][j];
        dp[i][j]=ans;
        return ans;
    }

    else {
        int op1=MinCost(cost,i,j-1,dp)+cost[i][j];
        int op2=MinCost(cost,i-1,j,dp)+cost[i][j];
        int ans= min(op1,op2);
         dp[i][j]=ans;
         return ans;
      }

}

int Bottomup(int cost[][4],int i,int j){

int dp[10][10]={0};

 for(int k=0;k<=i;k++){

    for(int l=0;l<=j;l++){

        if(k==0&&l==0){
            dp[k][l]=cost[k][l];
        }
        else if(k==0&&l>0){
            dp[k][l]=dp[k][l-1]+cost[k][l];
        }
        else if(k>0&&l==0){
            dp[k][l]=dp[k-1][l]+cost[k][l];
        }
        else{
            dp[k][l]=min(dp[k][l-1],dp[k-1][l])+cost[k][l];
        }
    }

 }
 return dp[i][j];

}

int main(){
  int cost[4][4]={ {1,1,3,5},
  {10,1,1,8},
  {5,6,1,1},
  {3,1,1,1}

};
int dp[100][100];
for(int i=0;i<100;i++){

		for(int j=0;j<100;j++){

			dp[i][j] = -1;

		}

	}
 int i,j;
 cin>>i>>j;
 cout<<MinCost(cost,i,j,dp)<<endl;
 cout<<Bottomup(cost,i,j) <<endl;



}
