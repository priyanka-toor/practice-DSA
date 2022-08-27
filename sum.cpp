#include<iostream>
using namespace std;
int sum(int n){
    if(n==0)
    return 0;

int s=sum(n/10);
return n%10+s;
}
int main()
{
    int n;
    cin>>n;
    int s=sum(n);
    cout<<s;
    return 0;
}