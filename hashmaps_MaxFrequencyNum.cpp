#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
int highestFrequency(int arr[], int n){
    unordered_map<int,int> f;
    int c=0;
    for(int i=0;i<n;i++){
        f[arr[i]]=0;
    }
    for(int i=0;i<n;i++){
        f[arr[i]]=f[arr[i]]+1;
    }
    int  m=arr[0];
    for(int i=0;i<n;i++){
        cout<<f[arr[i]]<<endl;
    }
    for(int i=0;i<f.size()-1;i++){
       
        if(f[m]<f[arr[i+1]]){
          m=arr[i+1];
        }
    }
    return m;
}
int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
    return 0;
}