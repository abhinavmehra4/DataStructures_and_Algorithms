#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int minSteps(int n) //BruteForce
{
    if(n<=1)
        return 0;
    int y=INT_MAX,z=INT_MAX;
    int x = minSteps(n-1);
    if(n%2==0)
        y = minSteps(n/2);
    if(n%3==0)
        z = minSteps(n/3);
    
    return 1+ min(x,min(y,z));
}

int minStepsHelper(int n, int* ans)
{
    //base case
     if(n<=1)
        return 0;

    //check if output exists
     if(ans[n]!=-1)
        return ans[n];
    
    //calculate output
    int y=INT_MAX,z=INT_MAX;
    int x = minStepsHelper(n-1,ans);
    if(n%2==0)
        y = minStepsHelper(n/2,ans);
    if(n%3==0)
        z = minStepsHelper(n/3,ans);
    
    int output = 1+ min(x,min(y,z)); 
    ans[n]=output; 

    return output;

}

int minSteps_2(int n) //Memoization
{
    int* ans = new int[n+1];

    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }

    return minStepsHelper(n,ans);

}

int main()
{
    int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
    cout<<minSteps_2(n)<<endl;

    return 0;
}