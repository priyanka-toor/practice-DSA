#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
vector<int> longestConsecutiveIncreasingSequence(int *a, int n){
  unordered_map<int,bool> l;
  vector<int> v;
  int maxLength=0;
  int start;
  for(int i=0;i<n;i++){
      l[a[i]]=true;
  }
  int len;
  int curr;
 /* for(int i=0;i<n;i++){
       curr=a[i];
      l[a[i]]=false;

         if(l.count(curr+1)>0){
              curr=curr+1;
              len++;
              l[curr]=false;
          }
          else if(l.count(curr-1)>0){
              curr=curr-1;
            len++;
            l[curr]=false;
          }
      //}
      maxLength=max(len,maxLength);
      start=curr;
    
  }*/
  for(int i=0;i<n;i++){
      curr=a[i];
      if(s.find(curr-1)==s.end()){
          int j=curr;
      }
  }
  for(int i=0;i<maxLength;i++){
      v.push_back(curr+0);
  }
  return v;
}
int main()
{
     int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
    return 0;
}