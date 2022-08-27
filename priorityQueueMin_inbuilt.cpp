#include<iostream>
using namespace std;
#include<queue>
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
   /* pq.push(2);
    pq.push(6);
    pq.push(10);
    pq.push(11);
    pq.push(13);
    pq.push(4);
    pq.push(1);
    pq.push(20);*/
    pq.push(6);
    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(7);
    pq.push(5);
    cout<<"size : "<<pq.size()<<endl;
    cout<<"top : "<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;
}