#include<iostream>
using namespace std;
bool checkPath(int** edges, int n,int a,int b){
  bool p;
  for(int i=0;i<n;i++){
       if(i==a){
           continue;
       }
      if(edges[a][i]==1){
          if(i==b){
              return true;
          }
          else
          p=checkPath(edges,n,i,b);
      }
  }
  return p;
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
   // print(edges,n,0,visited);
  int a,b;
  cin>>a>>b;
  /* if(checkPath(edges,n,a,b)){
       cout<<"true";
   }
   else{
   cout<<"false";

   }*/
   cout<<checkPath(edges,n,a,b);
    return 0;
}