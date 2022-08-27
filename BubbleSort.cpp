#include<iostream>
using namespace std;

int main(){
      int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=j+1;k<=j+1;k++)
            {
                if(a[k]<a[j]){
                    int temp=a[k];
                    a[k]=a[j];
                    a[j]=temp;
                }
            }
        }
   }
      cout<<"Sorted array ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}