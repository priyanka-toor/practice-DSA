#include<iostream>
using namespace std;
void print(int a[],int n,int o[] , int m){
  if(n==0){
    for(int i=0;i<m;i++){
      cout<<o[i]<<" ";
    }
     cout<<endl;
   return;
  }
 
 int output[20];
  output[m]=a[0];

for(int i=0;i<m;i++){
  output[i]=o[i];
 
}

  print(a+1,n-1,o,m);
 
   print(a+1,n-1,output,m+1);
}
void printSubsetsOfArray(int a[],int n){
    int o[20];
    
    print(a,n,o,0);
}
int main()
{
    int n;
  cin>>n;
  int a[n];
  for(int i=0; i < n; i++){
    cin>>a[i];
  }
  printSubsetsOfArray(a, n);
    return 0;
}