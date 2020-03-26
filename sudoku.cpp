//sudoku solver and checker
#include<iostream>
#include<math.h>
using namespace std;

bool isSafetoput(int mat[][9],int n,int i,int j,int number){
 for(int k=0;k<n;k++){
        if(mat[i][k]==number&&mat[k][j]==number)
            return false;
 }

 n=sqrt(n);
 int starti=(i/n)*n;
 int startj=(j/n)*n;

 for(int k=starti;k<starti+n;k++){
    for(int l=startj;l<startj+n;l++){
        if(mat[k][l]==number){
            return false;
        }
    }
 }
 return true;

}

bool sudokusolver(int mat[][9],int n,int i,int j){
//base case
if(i==n){
    //print the sudoku
    for(int k=0;k<n;k++){
         for(int l=0;l<n;l++){
                cout<<mat[k][l]<<" ";
         }
         cout<<endl;
    }
    return true;

}

if(j==n)
    return sudokusolver(mat,n,i+1,0);

if(mat[i][j]!=0)
   return sudokusolver(mat,n,i,j+1);

//recursive
for(int number=1;number<=n;number++){
    if(isSafetoput(mat,n,i,j,number)){
        mat[i][j]=number;
        bool kyabaakisolvehopaaya=sudokusolver(mat,n,i,j+1);
        if(kyabaakisolvehopaaya)
            return true;
    }
    mat[i][j]=0;

}
return false;//sudoku cannot be solved sare no rkh ke dekh liye for loop ke through

}



 int main()
 {
   int mat[9][9]=

       {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};


   sudokusolver(mat,9,0,0);

     return 0;
 }
