#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int lcs_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int** output = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            output[i][j] = -1;
        }
    }
    //FILL THE ARRAY ELEMENTS WHOSE VALUE WE ALREADY KNOW, 
        /*
        i.e we know that if size of any string is 0, lcs will be 0
        Hence for this case, the first row and column the values wil be 0. Because first row corresponds to 
        0 size of string 1 and first column corresponds to 0 size of string 2. Last row corresponds to mth 
        size of string s and last column corresponds to nth size of string t
        */
       
        //fill the first row
        for(int j =0;j<=n;j++)
        {
            output[0][j]=0;
        }
        //fill the first column
        for(int i=0;i<=m;i++)
        {
            output[i][0]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                //if first character matches
                if(s[m-i]==t[n-j])
                {
                    output[i][j]=1+ output[i-1][j-1];
                }
                //if first character doesnt match
                else
                {
                    int a = output[i-1][j];
                    int b = output[i][j-1];
                    int c = output[i-1][j-1];
                    output[i][j] = max(a,max(b,c));
                }
            }
        }
        return output[m][n];
}

int lcs_mem_helper(string s, string t, int** output)
{
    int m = s.size();
    int n = t.size();
   
    //BASE CASE: 
        if(s.size()==0 || t.size()==0)
            return 0;

//CHECK IF ANSWER EXISTS
    if(output[m][n]!=-1)//answer is stored. So return the answer as it is
    {return output[m][n];}
     int ans;
    //RECURSIVE CALL
        if(s[0]==t[0]) 
        {
             ans= 1+ lcs_mem_helper(s.substr(1),t.substr(1),output);
        }
        else
        {
            int a = lcs_mem_helper(s.substr(1),t,output); 
            int b = lcs_mem_helper(s,t.substr(1),output); 
            int c = lcs_mem_helper(s.substr(1),t.substr(1),output); 

             ans =  max(a,max(b,c));
        }
//SAVING CALCULATION AS A PART OF MEMOIZATION
    output[m][n]=ans;

return ans;

}

int lcs_mem(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int** output = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
        output[i] = new int[n+1];
        for(int j=0;j<=n;j++)
        {
            output[i][j] = -1;
        }
    }
    
    return lcs_mem_helper(s,t,output);
    
}

int lcs(string s, string t)
{
    //BASE CASE: 
    //when there is no common character we will arrive at a situation when size of one string is 0
    //that becomes our base case
        if(s.size()==0 || t.size()==0)
            return 0;

    //RECURSIVE CALL

        if(s[0]==t[0]) //if first character of both string is same
        {
            return 1+ lcs(s.substr(1),t.substr(1));
        }

        else{// when first character of each string does not match
        int a = lcs(s.substr(1),t); //drop the first character of string s only
        int b = lcs(s,t.substr(1)); //drop the first character pf string t only
        int c = lcs(s.substr(1),t.substr(1)); //drop the first charcaters of both string t and s

        return max(a,max(b,c));
   }
}

int main()
{
    string s,t;
    cin>>s>>t;
    cout<<lcs(s,t)<<endl;
    cout<<lcs_mem(s,t)<<endl;
    cout<<lcs_DP(s,t)<<endl;

    return 0;
}