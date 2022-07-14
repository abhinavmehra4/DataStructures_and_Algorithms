#include <iostream>
using namespace std;
#include <vector>


vector<int>* getPath(int **edges, int n, int v1, int v2, bool *visited)
{
    if(v1 == v2)
    {
        vector<int> *v = new vector<int>();
        v->push_back(v2);
        return v;
    }
    
    visited[v1] = true;
    
    for(int i=0;i<n;i++)
    {
        if(edges[v1][i] == 1 && !visited[i])
        {
            vector<int> *output = getPath(edges, n, i, v2, visited);
            if(output != NULL)
            {
                output->push_back(v1);
                return output;
            }
        }
    }
    
    return NULL;
}

vector<int> *getPathHelper(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    
    vector<int> *output = getPath(edges, n, v1, v2, visited);
    delete [] visited;
    return output;
}



int main() {
    
    // Write your code here
    
    int n, e;
    cin>>n>>e;
    
    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    
    int v1, v2;
    cin>>v1>>v2;
    
    vector<int> *vector = getPathHelper(edges, n, v1, v2);
    if(vector == NULL)
    {
        return 0;
    }
    
    for(int i=0;i<vector->size();i++)
    {
        cout<<vector->at(i)<<" ";
    }
    
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    
    delete [] edges;
    
}


