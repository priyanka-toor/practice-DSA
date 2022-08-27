#include<iostream>
using namespace std;
#include<queue>

void print(int** edges , int n ,int e, int sv , bool* visited){
    queue<int> q;
    q.push(sv);
    if(e==0){
        for(int i=0;i<n;i++){
            cout<<i<<" ";
        }
    }
    visited[sv]=true;
    if(e!=0){
    while(q.size()!=0){
       // visited[sv]=true;
    for(int i=0;i<n;i++){
          if(i==sv){
           continue;
       }
       if(edges[sv][i]==1){
           if(visited[i]){
               continue;
           }
           
          q.push(i);
          visited[i]=true;
       }
    }
    cout<<q.front()<<endl;
    q.pop();
    sv=q.front();
    }
    }
}
int main()
{
    int n;     // no. of vertices
    int e;  // no. of edges
    cin>>n>>e;
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int f,s; // f is first vertex and s is second vertex
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    print(edges,n,e,0,visited);

    return 0;
    
}