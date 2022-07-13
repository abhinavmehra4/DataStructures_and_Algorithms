#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int* a, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i =0;i<size;i++)
    {
        if(seen.count(a[i])>0)
        {
            continue;//so, if the key exists, no need to insert it. Hence loop starts all over again
        }
        seen[a[i]]=true;//this adds another key of the number and correspondin gto it, the truie boolean is fed in
        output.push_back(a[i]);
    }
    return output;
}

int main()
{
    int a[]={1,2,3,3,2,1,4,3,6,5,5};
    vector<int> output = removeDuplicates(a,11);
    for(int i =0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }

    return 0;
}