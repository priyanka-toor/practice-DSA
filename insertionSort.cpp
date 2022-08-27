#include<iostream>
using namespace std;
void swap(int a[],int i , int j){
   int temp=a[i];
   a[i]=a[j];
   a[j]=temp;
}
int main()
{
        int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int temp;
    for(int i=0;i<n-1;i++){
       
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]){
               swap(a,j,j+1);
            }
        }
    
    }
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}