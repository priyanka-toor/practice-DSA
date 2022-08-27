#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int strToNum(char c[]){
    int l=strlen(c);
    int a;
    
    if(l==1){
        return c[0]-'0';
    }
   a=strToNum(c+1);
 double  b=c[0]-'0';
   double  n=b*pow(10,l-1)+a;
    return (int)n;
  
   
  
}
int main()
{
    char c[50];
  cin >> c;
 //int n=c[0]-'0';
  int n=strToNum(c);
  cout << n;
    return 0;
}