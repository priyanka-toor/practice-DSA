#include<iostream>
using namespace std;
int LastIndex(int a[],int n,int x){
 
    if(a[n-1]==x){
        return n-1;
    }
     if(n==0){
      return -1;
  }
     int  i= LastIndex(a,n-1,x);
    if(i==-1){
        return -1;
    }
    else 
    return i;
}
int main()
{
       int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     int x;
    cin>>x;
    int i= LastIndex(a,n,x);
    cout<<i;
    return 0;
}