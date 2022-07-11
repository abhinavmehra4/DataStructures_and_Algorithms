#include<iostream>
using namespace std;

void print(int** edges,int n,int sv,bool* visited)//sv-starting verte
{
    cout<<sv<<endl;
    visited[sv]=true;//when vertices is visited, make it true
    for(int i=0;i<n;i++)
    {   
        if(i==sv){
            continue;
        }

        if(edges[sv][i]==1){
            if(visited[i])
                continue; //if vertices is already visited, skip it
            print(edges,n,i,visited);
        }
    }
}
int main()
{
    int n,e;
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
    bool* visited = new bool[n]; //keeps track of all the visited vertices
    for(int i =0;i<n;i++)
    {
        visited[i]=false;
    }
    print(edges,n,0,visited);//we take starting vertex as 0
    return 0;
}