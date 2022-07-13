#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

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
	cout << minCostPath(arr, n, m) << endl;
    return 0;
}