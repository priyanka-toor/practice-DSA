#include<iostream>
using namespace std;
#include<queue>
#include<vector>
vector<int> getArray( priority_queue<int,vector<int>,greater<int>> pq){
    vector<int> v;
    while(pq.size()!=0){
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
int getMedian(vector<int> v){
    int m;
    int n=v.size();
    if(n%2==0){
    m=(v[(n-1)/2]+v[(n+1)/2])/2;
    }
    else{
        m=v[n/2];
    }
    return m;
}
void findMedian(int *arr, int n){
 priority_queue<int,vector<int>,greater<int>> pq;
 int m[n];
 for(int i=0;i<n;i++){
     pq.push(arr[i]);
     vector<int> v=getArray(pq);
  m[i]=getMedian(v);
  cout<<m[i]<<" ";
 }
}
int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
    return 0;
}