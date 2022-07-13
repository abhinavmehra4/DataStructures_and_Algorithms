#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maze[18][18];
void printSolution(int** solution, int n)
{
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<solution[i][j]<<" ";
        }
    }
    cout<<endl;
}

void mazeHelp(int maze[][18],int n, int** solution, int x, int y)
{   /*WHEN WE CANNOT MOVE AHEAD*/
        //We get to print
        if(x== n-1 && y==n-1)
            {
                solution[x][y]=1;
                printSolution(solution,n);
                solution[x][y]=0; //backtracking
                return;
            }
        //When we dont get to print
        if(x>=n || x<0 || y>=n || y<0 || maze[x][y]==0 || solution[x][y]==1)
            return;
        
        /*THESE ARE THE PATHS WHERE WE CAN MOVE AHEAD*/
        solution[x][y]=1;
        mazeHelp(maze,n,solution,x-1,y); //UP
        mazeHelp(maze,n,solution,x+1,y); //DOWN
        mazeHelp(maze,n,solution,x,y-1); //LEFT
        mazeHelp(maze,n,solution,x,y+1); //RIGHT

        solution[x][y]=0; //backtrack
}

void ratInMaze(int maze[][18],int n)
{
 int** solution = new int*[n]; //This is matrix
 for(int i =0;i<n;i++)
 {
     //So in every row, there is an array of n size
     solution[i] = new int[n]; 
 }
    //initialization of solution 2d arrays
    for(int i=0; i<n; i++)
    {
        memset(solution[i], 0, n*sizeof(int));
    }

     mazeHelp(maze,n,solution,0,0); //0,0 is the starting point
 
}

int main()
{	
    int n;
	cin>>n;
    // int maze[n][n];
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    ratInMaze(maze,n);
    return 0;
}
