#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int board[11][11]; //default chessboard of size 11x11. This is a matrix of 11 by 11

bool isPossible(int n, int row, int col)
{
    /*
        Since we are inserting row wise, we only have to keep track of three things. That there is no queen
            1. vertically upwards
            2. upwards-right diagonal
            3. upwards-left diagonal
        There is no need to check downward direction because no queen is there anyways as we insert in row by row fashion
    */

   //upper same column
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
            return false;   
    }
   //upper left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
       if(board[i][j]==1)
            return false;
    }
    //upper right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n ;i--,j++)
    {
        if(board[i][j]==1)
            return false;
    }
    return true;
}

void nQueenHelper(int n ,int row)
{
    if(row==n)
    {
        //we have reached some solution
        //so print the board matrix 
        //return
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    //since the above case fails
    //Place at all POSSIBLE poisitons and move to smaller Problem
    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j)) //isPossible(n,row,column). This tells if we can place the queen or not
        {
            board[row][j]=1;
            nQueenHelper(n,row+1);
            //after this we have to backtrack to find another solution by placing the queen somewhere else. For that we do
            board[row][j]=0;
        }   
    }
    return; //because we have nothing left to do
}

void placeNqueens(int n ){

    memset(board,0,11*11*sizeof(int));
    //memset(variable to initialize, what to value to initialize variable with, size of variable)
    nQueenHelper(n,0);
}

int main()
{   
    int n ;
    cout<<"Enter the value of 'n'"<<endl;
    cin>>n;
    placeNqueens(n);
    return 0;
}