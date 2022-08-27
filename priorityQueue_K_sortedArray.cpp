#include<iostream>
using namespace std;
#include<queue>
void KSortedArray(int input[] , int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){// time complexity for this loop ----> klogk (as in insertion in max heap take nlogn time for n elements)
        pq.push(input[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){ // time complexity for this loop ---- (n-k)logk (in this loop we are removing element from priority queue so in max heap for removing element it take nlogn for n element)
      input[j]=pq.top();
      pq.pop();
      pq.push(input[i]);
      j++;
    }
    while(!pq.empty()){// time complexity for this loop ----> klogk
        input[j]=pq.top();
        pq.pop();
        j++;
    }
    // total time complexity : (n+k)logk = nlogk 
    // when n>>>>k  , then k is negligble then T.C is O(n);
}
int main()
{
    int input[]={10,12,6,7,9};
    int k=3;
    KSortedArray(input,5,k);
    for(int i=0;i<5;i++){
        cout<<input[i]<<" ";
    }
    return 0;
}