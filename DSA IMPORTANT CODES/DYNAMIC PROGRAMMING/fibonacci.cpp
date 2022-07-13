#include<iostream>
using namespace std;

int fibo(int n)
{
    if(n<=1)
        return n;
    int a = fibo(n-1);
    int b = fibo(n-2);

    return a+b;
}

int fibo_helper(int n, int* ans)
{
    if(n<=1)
        return n ;
    
    //check if output already exits
    if(ans[n]!=-1)
        return ans[n];
    
    int a = fibo_helper(n-1,ans);
    int b = fibo_helper(n-2,ans);

    //save output for future use
    ans[n]=a+b;

    return ans[n];
}

int fibo2(int n)
{
    //array to store the value. 
    int* ans = new int[n+1];
    //since we dont want array to change every time recursion is done, to avoid that we use helper function
    for (int i = 0; i <= n; i++)
    {
        ans[i]=-1; //we initialized every value with -1. Hence -1 shows that array index is empty
    }

    return fibo_helper(n,ans);
    
}

int fibo3(int n)
{
    int* ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;

    for (int i = 2; i <= n; i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }

    return ans[n];
     
}

int main()
{
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    cout<<fibo2(n)<<endl;
    return 0;
}