#include<iostream>
using namespace std;
int firstIndex(int a[],int n,int x){
 
    if(a[0]==x){
        return 0;
    }
     if(n==0){
      return -1;
  }
     int  i=firstIndex(a+1,n-1,x);
    if(i==-1){
        return -1;
    }
    else 
    return i+1;
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
    int i=firstIndex(a,n,x);
    cout<<i;
    return 0;
}