#include<iostream>
using namespace std;
void swap(int a[],int i , int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void merge(int input[] ,int s,int e){
   
  int output[e-s+1];
    int i=s,mid=(s+e)/2,j=mid+1;
    int k=0;
    while(i<=mid && j<=e){
        if(input[i]<input[j]){
            output[k++]=input[i];
            i++;
        }
        else{
            output[k++]=input[j];
            j++;
        }
    }
    while(i<=mid){
        output[k++]=input[i];
            i++;
    }
    while(j<=e){
        output[k++]=input[j];
            j++;
    }
    for(int i=0;i<e-s+1;i++){
        input[s+i]=output[i];
    }

}
void m_sort(int a[] , int s , int e){
    if(s>=e){
        return;
    }
    int m=(s+e)/2;
    m_sort(a,s,m);
  //  cout<<"i"<<endl;
    m_sort(a,m+1,e);
  //  cout<<"j"<<endl;
  merge(a,s,e);
}
void mergeSort(int a[] , int n){
    if(n==0||n==1){
        return;
    }
   m_sort( a , 0,n-1);

    
}
int main()
{
      int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,n);
     for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
    return 0;
}