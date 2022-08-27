#include<iostream>
using namespace std;
bool checknum(int a[], int n, int x){
    if(a[0]==x){
        return true;
    }
    if(n<1){
        return false;
    }
    bool isfind=checknum(a+1,n-1,x);
    return isfind;
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
    if(checknum(a,n,x)){
        cout<<"find"<<endl;
    }
    else{
        cout<<"Not find"<<endl;
    }
    return 0;
}