#include<iostream>
using namespace std;
/*int  fib(int n){     T.C : 2 ki power n
  if(n<=1){
      return n;
  }
  int a=fib(n-1);
  int b=fib(n-2);
  return a+b;
}*/
//******** BELOW TECHNIQUE IS KNOWN AS ""MEMOIZATION"" *******
int fibo_helper(int n, int *ans){      //T.C:O(n)
    if(n<=1){
        return n;
    }
    // check if output already exists
   if(ans[n]!=-1){
       return ans[n];
   }
   int a=fibo_helper(n-1,ans);
   int b=fibo_helper(n-2,ans);
   // save the ouptut for future use
   ans[n]=a+b;

    return ans[n];
}
//******** ABOVE TECHNIQUE IS KNOWN AS ""MEMOIZATION"" *******
int fibo_2(int n){
    int *ans=new int[n+1];
     for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}
int main(){
    int n;
    cin>>n;
    //cout<<fib(n);
    cout<<fibo_2(n);
}
//**** MEMOIZATION: It is top down approach ******