#include<iostream>
#include<queue>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited)//sv-starting verte
{
    cout<<sv<<" ";
    visited[sv]=true;//when vertices is visited, make it true
    for(int i=0;i<n;i++)
    {   
        if(i==sv){
            continue;
        }

        if(edges[sv][i]==1){
            if(visited[i])
                continue; //if vertices is already visited, skip it
            printDFS(edges,n,i,visited);
        }
    }
    
}

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

void DFS(int** edges, int n)
{
    bool* visited = new bool[n]; //keeps track of all the visited vertices
    for(int i =0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
                printDFS(edges,n,i,visited);

    }
    delete[] visited;
    
}

void BFS(int** edges, int n)
{
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
    
    cout<<endl<<"DFS"<<endl;
    DFS(edges,n);
    cout<<"BFS"<<endl;
    BFS(edges,n);

    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete edges;
    return 0;
}