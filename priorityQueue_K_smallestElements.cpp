#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<queue>
vector<int> kSmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    vector<int> output;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        int max=pq.top();
        if(max>arr[i]){
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

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kSmallest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
    return 0;
}