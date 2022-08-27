#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0)
    {
        return 1;
    }
    int SmallOutput=factorial(n-1);
    cout<<"when n is "<<n<<" then SmallOutput is "<<SmallOutput<<endl;
    return n*SmallOutput;
}
int main()
{
    int n;
    cin>>n;
    int f=factorial(n);
    cout<<f;

    return 0;
}