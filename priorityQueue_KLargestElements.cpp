#include<iostream>
using namespace std;
#include<queue>
vector<int> kLargest(int arr[], int n, int k){
 priority_queue<int,vector<int>,greater<int>> pq;
 vector<int> output;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int min=pq.top();
        if(min<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty()){
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}
int main()
{
    int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
    
    int k;
    cin >> k;
    
    vector<int> output = kLargest(input, size, k);
    for(int i = 0; i < output.size(); i++)
        cout << output[i] << endl;
    return 0;
}