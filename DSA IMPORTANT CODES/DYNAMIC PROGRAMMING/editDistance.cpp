#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int editDistanceMemoizationHelper(string s, string t, int** visited)
{
    int m = s.size();
    int n = t.size();

    
    //BASE CASE
    if(s.size()==0 || t.size()==0)
        return max(s.size(),t.size());
    
    if(visited[m][n]!=-1)
        return visited[m][n];
    int ans;
    //RECURSIVE CALLS
    if (s[0]==t[0])
    {
        ans = editDistanceMemoizationHelper(s.substr(1),t.substr(1),visited);
    }
    else{
        //insert
        int x = editDistanceMemoizationHelper(s.substr(1),t,visited) + 1;
        //delete
        int y = editDistanceMemoizationHelper(s,t.substr(1),visited) + 1;
        //replace
        int z = editDistanceMemoizationHelper(s.substr(1),t.substr(1),visited) + 1;

        ans =  min(x,min(y,z));
    }
    visited[m][n]=ans;

    return ans;
        
}

int editDistanceMemoization(string s , string t)
{
    int m = s.size();
    int n = t.size();

    int** visited = new int*[m+1];
    for(int i =0;i<=m;i++)
    {
        visited[i] = new int[n+1];
        for(int j =0;j<=n;j++)
        {
            visited[i][j]=-1;
        }
    }

    return editDistanceMemoizationHelper(s,t,visited);

}

int editDistance(string s, string t)
{
   
    //BASE CASE
    if(s.size()==0 || t.size()==0)
        return max(s.size(),t.size());
    

    //RECURSIVE CALLS
    if (s[0]==t[0])
    {
        return editDistance(s.substr(1),t.substr(1));
    }
    else{
        //insert
        int x = editDistance(s.substr(1),t) + 1;
        //delete
        int y = editDistance(s,t.substr(1)) + 1;
        //replace
        int z = editDistance(s.substr(1),t.substr(1)) + 1;

        return min(x,min(y,z));
    }
    
        
}

int main()
{
    string s,t;

    cin>>s>>t;

    cout<<editDistance(s,t)<<endl;

    return 0;
}