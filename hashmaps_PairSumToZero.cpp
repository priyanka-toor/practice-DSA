#include<iostream>
using namespace std;
#include<unordered_map>
int pairSum(int *a, int n) {
	// Write your code here
    unordered_map<int,int> c;
    
  int p=0;
  for(int i=0;i<n;i++){
      // instead of doing that much what you
      // did in your code simply declare a negative int 
      
      int negative  = -a[i];
      // and now find this negative in map using properties 
      // below if just check weather the thing we are find is present in 
      //map or not 
      
      if(c.find(negative) !=c.end()){

    
          p = p + c[negative];
          // we added frequency of the negative no. beacuse we can 
          //make pair with every one as its given array can contain duplicate elements 
          
      }
      c[a[i]]++;
     // cout<<i<<","<<c[a[i]]<<","<<","<<c.end()<<endl;
      
  }
  return p;
}

//simply the logic behind was like we have to find sum 0 pair 
// and this will happen if and only if we have same value negative interger 
// present in our array otherwise it cant happen 
int main()
{
     int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
    return 0;
}