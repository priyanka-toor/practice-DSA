#include<iostream>
using namespace std;
void increment(int n){
    cout<<n<<" ";
}
int main(){
    int i=10;
    int &j=i;
    i++;
    cout<<"i = "<<i<<endl;
    cout<<"j= "<<j<<endl;
    j++;
     cout<<"i = "<<i<<endl;
    cout<<"j= "<<j<<endl;
    int k=100;
    j=k;  // memeory of j is still same 
      cout<<"i = "<<i<<endl;
    cout<<"j= "<<j<<endl;
    increment(j++);
      cout<<"i (after using increment function )= "<<i<<endl;

}