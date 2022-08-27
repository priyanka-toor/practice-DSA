#include<iostream>
using namespace std;
bool is_sorted(int a[],int n){
if(n==0||n==1){
    return true;
}
if(a[0]>a[1]){
    return false;
}
bool smallSorted=is_sorted(a+1,n-1);

return smallSorted;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(is_sorted(a,n)){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    
    return 0;
}