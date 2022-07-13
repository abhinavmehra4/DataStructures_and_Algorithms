#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
#define N 9
bool findEmptyLocation(int grid[N][N], int &row, int &col)
{
    for(int i =0;i<N;i++)
    {   
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==0) //if any cell in the grid is empty, return the value of the row and column.
            {
                row=i;
                col=j;
                return true;
                //call by reference directly affects the parameters of the passed identifiers.
            }
        }
        cout<<endl;
    }
    return 0;

}

bool isSafeInRow(int grid[N][N],int row, int num)
{
    for(int i =0;i<N;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    return true;
}

bool isSafeInColumn(int grid[N][N],int col, int num)
{
    for(int i =0;i<N;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    return true;
}

bool isSafeInGrid(int grid[N][N],int row, int col, int num)
{
    int rowFactor = row - (row%3);
    int colFactor = col -(col%3);

    for(int i =0;i<3;i++)
    {    
        for(int j=0;j<3;j++)
        {
            if(grid[i+rowFactor][j+colFactor]==num)
                return false;
        }
    }
    return true;
}


bool isSafe(int grid[N][N],int row, int col, int num)
{
    if(isSafeInColumn(grid,row,num) && isSafeInRow(grid,row,num) && isSafeInGrid(grid,row,col,num))
        return true;
    return false;
}

bool solveSudoku(int grid[N][N])
{
    //find empty location. So for that, we need row and column
    int row, col;
    if(!findEmptyLocation(grid,row,col)) //if Iam not able to find empty location, means that the row is filled. Hence return true
        return true;
    
    for(int i=0;i<9;i++) //out of 1-9 only 1 number can be filled
    {
        if(isSafe(grid,row,col,i)) //is it safe to place nuber i in the empty space
        {
            grid[row][col]=i;
            if(solveSudoku(grid))
            {
                return true;
            }
            grid[row][col]=0;//backtrack again
        }
    }
    //IF IT IS STILL NOT ABLE TO SOLVE SUDOKU FOR VALUES 1-9, return false
    return false;
}

int main()
{   int grid[N][N];
    for(int i =0;i<N;i++)
    {   
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            grid[i][j]=s[j]-'0'; //ASCII VALUE OF 0 SUBTRACTED ROM THE ASCI VALUE OF NUMBERS GIVES THE LITERAL VALUE OF THE NUMBER
        }
    }
   
    solveSudoku(grid);

    for(int i =0;i<N;i++)
    {   
        for(int j=0;j<N;j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}
//123456789