#include<iostream>
using namespace std;
#include<stack>
int* stockSpan(int *price, int n){
    int *o=new int[n];
    int count;
    stack<int> s;
   for(int i=0;i<n;i++){
    s.push(price[i]);
   }
   int m=s.size();
   for(int i=s.size()-1;i>=0;i--){
       if(s.top()>=price[i]){
           o[m--]=s.size();
           s.pop();
       }
       else
       o[m--]=1;
       s.pop();
   }
    return o;
}
int main()
{
      int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
    return 0;
}