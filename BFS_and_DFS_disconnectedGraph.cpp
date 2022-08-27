#include<iostream>
using namespace std;
#include<queue>
void printDFS(int** edges, int n , int sv,bool* visited){ // sv is starting vertex
   cout<<sv<<endl;
   visited[sv]=true;
   for(int i=0;i<n;i++){
       if(i==sv){
           continue;
       }
       if(edges[sv][i]==1){
           if(visited[i]){
               continue;
           }
           printDFS(edges,n,i,visited);
       }
   }
}
void printBFS(int** edges , int n , int sv , bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
   
    while(q.size()!=0){
       // visited[sv]=true;
       int currentVertex=q.front();
         q.pop();
         cout<<currentVertex<<endl;
  
    for(int i=0;i<n;i++){
          if(i==currentVertex){
           continue;
       }
       if(edges[currentVertex][i]==1&&!visited[i]){
          q.push(i);
          visited[i]=true;
       }
    }
    }
    //delete[] visited;
}
void BFS(int** edges, int n){
 bool* visited=new bool[n];
  for(int i=0;i<n;i++){
        visited[i]=false;
    }
  for(int i=0;i<n;i++){
  if(!visited[i]){
       printBFS(edges,n,i,visited);
  }
   }
   delete[] visited;
}
void DFS(int** edges, int n){
 bool* visited=new bool[n];
  for(int i=0;i<n;i++){
        visited[i]=false;
    }
  for(int i=0;i<n;i++){
  if(!visited[i]){
       printDFS(edges,n,i,visited);
  }
   }
   delete[] visited;
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
   
   
    cout<<"DFS : "<<endl;
    DFS(edges,n);
    cout<<"BFS : "<<endl;
    BFS(edges,n);

    return 0;
}