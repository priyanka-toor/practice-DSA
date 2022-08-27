#include<iostream>
using namespace std;
int b_search(int a[] , int s, int e , int k){
    if(s>e){
        return -1;
    }
    int m=(s+e)/2;
    int i;
    if(a[m]==k){
        return m;;
    }else{
    if(k<a[m]){
        return b_search(a,s,m-1,k);
    }
    else
   
      return b_search(a,m+1,e,k);
    
    }
    

}
int binary_search(int a[] , int n ,int k){
    int i=b_search(a,0,n-1,k);
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
    int k;
    cout<<"Enter search value"<<endl;
    cin>>k;
    int index=binary_search(a,n,k);
    cout<<index;
    return 0;
}