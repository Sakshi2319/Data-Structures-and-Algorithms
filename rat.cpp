//rat in maze
#include<iostream>
using namespace std;

bool ratinmaze(char maze[][10],int m,int n,int sol[][10],int i,int j)
{
    //base case
    if(i==m-1&&j==n-1)
    {
        sol[i][j]=1;
        //print the sol matrix
        for(int k=0;k<m;k++){
            for(int l=0;l<n;l++){
            cout<<sol[k][l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true; //return false for all the solutions

    }


    //recursive
    sol[i][j]=1;//jahan khade ho part of solution\
    //check rightwards
    if(j+1<n&&maze[i][j+1]!='X'){
        bool kyarightsemazesolvehui=ratinmaze(maze,m,n,sol,i,j+1);
        if(kyarightsemazesolvehui)
            return true;

    }
    //check downwards
    if(i+1<m && maze[i+1][j]!='X')
    {
        bool kyaneechesemazesolvehui=ratinmaze(maze,m,n,sol,i+1,j);
        if(kyaneechesemazesolvehui)
        {
            return true;
        }
    }

    sol[i][j]=0;
    return false;
}


int main()
{
    char maze[][10]={
    "0000",
    "00XX",
    "0000",
    "XX00"
    };//X represents path blocked
    int sol[10][10]={0};
    ratinmaze(maze,4,4,sol,0,0);//0,0 is source and m-1,n-1 is destination
    return 0;
}
