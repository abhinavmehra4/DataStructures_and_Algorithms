#include<bits/stdc++.h>
using namespace std;
int staircaseRecursion(int n)
{
    
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
        return 0;
    else
    {
        int a=staircaseRecursion(n-2);
    	int b=staircaseRecursion(n-3);
		int c=staircaseRecursion(n-1);
    
    
    return a+b+c;
    }
}
int staircaseHelper(int n,int* ans)
{
    if(n==0)
        return 1;
    else if(n<0)
        return 0;
    
    else if(ans[n]!=-1)
        {
            return ans[n];
        }
    else{
        
        int a=staircaseHelper(n-2,ans);
    	int b=staircaseHelper(n-3,ans);
		int c=staircaseHelper(n-1,ans);

        int output = a+b+c;
        ans[n] = output;
        return output;
    }
}
int staircaseMemoization(int n)
{
    int* arr = new int[n+1];//since there are n stairs, there will be an array of n+1
    for(int i=0;i<n;i++)
    {
        arr[i]=-1;
    }

    return staircaseHelper(n,arr);
}

int main(){
    int num;
    cin>>num;
    int count=0;
    int n;
    while(count!=num)
    {
        cin>>n;
        cout<<staircaseRecursion(n)<<endl;
        cout<<staircaseMemoization(n)<<n;
        count++;
    }
    
    // write your code here
    return 0;
}