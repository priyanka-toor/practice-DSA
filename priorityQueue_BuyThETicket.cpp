#include<iostream>
using namespace std;
#include<queue>
int buyTicket(int *arr, int n, int k){
 priority_queue<int> pq;
 queue<int> q;
 for(int i=0;i<n;i++){
     q.push(i);
     pq.push(arr[i]);
     
 }
 int count=0;
 while(q.front()!=k||pq.top()!=arr[k]){
     int j=q.front();
     if(pq.top()==arr[j]){
         pq.pop();
         count++;
         q.pop();
     }
     else{
         q.pop();
         q.push(j);
     }
    
   
 }
    return count+1;
}
int main()
{
     int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
    return 0;
}