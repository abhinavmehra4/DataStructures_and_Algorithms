#include<iostream>
#include<queue>
using namespace std;

bool hasPathHelper(int** edges, int v,int sv, int ev,bool* visited)
{
    if(edges[sv][ev]==1)
        return true;
    visited[sv]=true;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && edges[sv][i]==1)
        {
            return hasPathHelper(edges,v,i,ev,visited);
        }
    }
    return false;
}

void hasPath(int** edges, int v,int sv,int ev){
    
    bool* visited = new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    bool ans = hasPathHelper(edges,v,sv,ev,visited);
     if(ans)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

}


int main()
{
    int v,e;
    cin>>v>>e;

    int** edges = new int*[v];
    for(int i =0;i<v;i++)
    {
        edges[i]=new int[v];
        for(int j=0;i<v;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int sv,ev;
    cin>>sv>>ev;
    hasPath(edges,v,sv,ev);
   

    for(int i=0;i<v;i++)
    {
        delete[] edges[i];
    }
    
    delete [] edges;
    return 0;
}