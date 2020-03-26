#include<iostream>
using namespace std;

bool isSafetoPut(int board[][10],int n , int i,int j)
{
    for(int k=0;k<n;k++)
    {
        if(board[i][k]==1||board[k][j]){//row vary col fix; col vary row fix ;row=i,col=j //row checked
            return false;
        }
    }
    int r=i;//row
    int c=j;//col
    //left diagnol
    while(r>=0&&c>=0)//as both were decresing
    {
        if(board[r][c]){
            return false;
        }
        r--;
        c--;
    }
    //right diagnol
    r=i;
    c=j;
    while(r>=0&&c<n)
    {
        if(board[r][c])
        {
            return false;
        }
        r--;
        c++;
    }
    return true;

}
bool nqueen(int board[][10],int n,int i)
{
    //base case
    if(i==n){
        //print the board
        for(int k=0;k<n;k++){
         for(int l=0;l<n;l++){
            cout<<board[k][l]<<" ";
         }
         cout<<endl;
        }
        cout<<endl;
        return false; //return true ek sol aayega

    }
    //recursion
    for(int j=0;j<n;j++)//j iterator to move queen
    {
        if(isSafetoPut(board,n,i,j)==true){
            board[i][j]=1;//place the queen
            bool kyabaakibaatbani=nqueen(board,n,i+1);
            if(kyabaakibaatbani)
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;//as pure loop mein iterate krliya we cannot place the queen
}


int main()
{
    int board [10][10]={0};//queen raknna is 1 and queen nahi hai mtlb 0
    int n ;
    cin>>n;//n= 2and 3 not possible

    nqueen(board,n,0);//0 is the current row

    return 0;
}
