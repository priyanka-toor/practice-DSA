#include <iostream>
using namespace std;
int Lsearch(int a[] , int n ,int k){
    for(int i=0;i<n;i++){
        if(a[i]==k){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"Enter search value"<<endl;
    cin>>k;
   int s=Lsearch(a,n,k);
   if(s==-1){
       cout<<"No search found"<<endl;
   }
   else{
       cout<<"Search found at index "<<s<<endl;
   }
}