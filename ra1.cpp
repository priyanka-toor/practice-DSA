#include<iostream>
using namespace std;
double gs(int k){
     if(k==0){
        return 1;
    }
    if(k<0){
        return 0;
    }
    double a;
   
      a=gs(k-1)+(1.0/2.0)*gs(k-2);
     // return a;
  double  ans=a+(1.0/2.0)*gs(k-1)-k;
    return ans;
      //  return (1.0/2.0)*a+a;
      // return ans;
   
    
}
int main()
{
    int k;
    cin>>k;
    double g=gs(k);
    cout<<g;
    return 0;
}