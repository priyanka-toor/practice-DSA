#include<iostream>
using namespace std;
int count(int n){
     int smallAns;
    if(n ==0){
       return 0;
    }
   smallAns = count(n / 10);
   cout<<"when n "<<n<<" smallAns "<<smallAns<<" ";
    return smallAns+1;
}
int main()
{
    int c=count(15);
    cout<<c;
    return 0;
}