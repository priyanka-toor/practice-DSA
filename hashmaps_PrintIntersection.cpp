#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
void printIntersection(int a[], int b[], int n, int m){
 unordered_map<int,int> c;
  for(int i=0;i<n;i++){
      if(c.count(a[i])==0){
          c[a[i]]=1;
      }
      else{
          c[a[i]]=c[a[i]]+1;
      }

  }
  for(int i=0;i<m;i++){
      if(c.count(b[i])==1){
          if(c[b[i]]==0){
              continue;
          }
              cout<<b[i]<<endl;
              c[b[i]]=c[b[i]]-1;
      }
  }
}
int main()
{
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
    return 0;
}