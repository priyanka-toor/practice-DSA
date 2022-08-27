#include <iostream>
using namespace std;
int Bsearch(int a[] ,int k, int b, int c){
   for(int i=b;i<c;i++){
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
   int m=n/2;
   int s;
   int j=0;
   if(k<a[m]){
      s=Bsearch(a,k,j,m);
   }
   if(k>a[m]){
       s=Bsearch(a,k,m,n);
   }
    if(s==-1){
       cout<<"No search found"<<endl;
   }
   else{
       cout<<"Search found at index "<<s<<endl;
   }
}