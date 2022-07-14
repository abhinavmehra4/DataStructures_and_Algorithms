#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int minCostPath_DP(int** input,int m, int n)
{
    //FIND THE FUNCTION CALL WHICH ISN'T DEPENDING ON SUBSEQUENT CALLS. 
    //Such cells are last 3 corner cells
    //AND SINCE DP IS BOTTOM-UP APPROACH THIKN ABOUT BUILDING THE PORBLEM FROM BOTTOM TO THE TOP
    int** output = new int*[m];
    for(int i =0;i<m;i++)
    {
        output[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            output[i][j]=-1;
        }
    }
    output[m-1][n-1]=input[m-1][n-1]; //we know this.
    //Fill last row(right to left)
    for(int j=n-2;j>=0;j--)
    {
        output[m-1][j] = output[m-1][j+1]+ input[m-1][j];
    }

    //fill last column(bottom to up)
    for(int i=m-2;i>=0;i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    //fill remaining cells
    for(int i =m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j] = min(output[i+1][j+1],min(output[i][j+1],output[i+1][j])) + input[i][j];
        }
    }

    return output[0][0];
}

int minCostPath_Mem_Helper(int** input,int m,int n,int i,int j,int** output)
{

    //BASE CASE
    if(i==m-1 && j==n-1)
        return input[i][j];

    if(i>=m ||j>=n){
        return INT_MAX;
    }

    //IF VALUE PRESENT
    if(output[i][j]!=-1)
    {
        return output[i][j];
    }

    //IF VALUE NOT PRESESNT
    int x = minCostPath_Mem_Helper(input,m,n,i+1,j,output);
    int y = minCostPath_Mem_Helper(input,m,n,i+1,j+1,output);
    int z = minCostPath_Mem_Helper(input,m,n,i,j+1,output);
    
    int ans = min(z,min(x,y)) + input[i][j];
    
    //save answer fopr future use
    output[i][j]=ans;

    return ans;

}

int minCostPath_Mem(int** input,int m,int n)
{

    int** output = new int*[m];
    for(int i =0;i<m;i++)
    {
        output[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            output[i][j]=-1;
        }
    }

    return minCostPath_Mem_Helper(input,m,n,0,0,output);

}

int minCostPathHelper(int** input,int m,int n,int i,int j)
{
    //base case
    if(i==m-1 && j==n-1)
        return input[i][j];

    //incase we are calling on an invalid cell, return
    if(i>=m ||j>=n){
        return INT_MAX;
    }

    //recursive calls
    int x = minCostPathHelper(input,m,n,i+1,j); //the end point remains the same as m-1 and n-1 so we put m and n same as before
    int y = minCostPathHelper(input,m,n,i+1,j+1);
    int z = minCostPathHelper(input,m,n,i,j+1);
    
    int ans = min(z,min(x,y)) + input[i][j];
    
    return ans;
}

int minCostPath(int** input,int m,int n)
{
    return minCostPathHelper(input,m,n,0,0);
}

int main()
{
    
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout<<minCostPath(arr, n, m)<<endl;
    cout<<minCostPath_Mem(arr,n,m)<<endl;
    cout<<minCostPath_DP(arr,n,m)<<endl;
    return 0;
}