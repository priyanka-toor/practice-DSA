#include<iostream>
using namespace std;
int sum(int a[],int n){
if(n==1||n==0){
    return a[0];
}
int smallSum=sum(a+1,n-1);

return smallSum+a[0];
}
int main()
{
       int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=sum(a,n);
    cout<<s;
    return 0;
}