#include<iostream>
using namespace std;
#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k){
   unordered_map<int,int> m;
    int c=0;
    for(int i=0;i<n;i++){
        
        int t=arr[i]+k; //5 + 3 = 8
        // (t - arr[i] = k) (arr[i] - t = k)
        if(m.find(t)!=m.end()){
         c += m[t];
        }
        t = arr[i] - k;
        if(k != 0) {
            if(m.find(t)!=m.end()){
             c += m[t];
            }
        }
        m[arr[i]]++; // [4,0] --> [4,1]
    }
    return c;
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    return 0;
}