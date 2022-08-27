#include<iostream>
using namespace std;
int mul(int m,int n){
    if(n==1){
    return m;
    }
    int smallMul=mul(m,n-1);
    return smallMul+m;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int p=mul(m,n);
    cout<<p;
    return 0;
}