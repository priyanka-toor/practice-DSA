#include<iostream>
using namespace std;
int countZero(int n){
   // cout<<n<<endl;
  if(n==0){
    return 0;
  }  
    if(n%10==0)
        return 1+countZero(n/10);
      else
      return 
      countZero(n/10);
    
    
     
}
int main()
{
    int n;
    cin>>n;
    int z=countZero(n);
    cout<<z;
  //  return 0;
}