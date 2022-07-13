#include<iostream>
#include<queue>
using namespace std;



void printBFS(int** edges,int n,int sv,bool* visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<" ";
        for(int i =0;i<n;i++)
        {
            if(i==currentVertex)
                continue;
            if(edges[currentVertex][i]==true && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }

    }
}

void BFS(int** edges, int n)
{
    if(n==0)
        return;
    bool* visited = new bool[n]; //keeps track of all the visited vertices
    for(int i =0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
                printBFS(edges,n,i,visited);

    }
    delete[] visited;
}

int main()
{
    int n,e; //n-number of vertices, e-number of edges
    cin>>n>>e;
    //creating the Adjacency matrix of nxn dynamically and initializing it with 0

    int** edges = new int*[n];
    for(int i =0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    //taking input from user now
    for(int i=0;i<e;i++)
    {
        int f,s; //first and second vertex
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    BFS(edges,n);

    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete edges;
    return 0;
}