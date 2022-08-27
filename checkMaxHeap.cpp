#include<iostream>
using namespace std;
#include<climits>
bool ans(int a[],int n, int i){
     if(i==n-1){
        return true;
    }
     bool b;
    int LCI=2*(i)+1;
    int RCI=2*(i)+2;
    if(LCI<n&&a[i]<a[LCI]){
        return false;
    }
    if(RCI<n&&a[i]<a[RCI]){
        return false;
    }
     i=i+1;
     b= ans(a,n,i);
    return b;
}
bool isMaxHeap(int a[], int n){
  return ans(a,n,0);
}
int main()
{
     int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
    return 0;
}