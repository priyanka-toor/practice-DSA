#include<iostream>
#include<string.h> 
using namespace std;
bool ispal(char c[], int s, int e){
    if(s==e){
        return true;
    }
    if(c[s]!=c[e]){
        return false;
    }
    else
    bool b=ispal(c+1,s+1,e-1);
    return true;
}

bool palindrome(char c[]){
  
   int l= strlen(c);
   int s=0;
   int e=l-1;
    bool b=ispal(c,s,e);
 return b;


  
}


int main()
{
    char c[50];
    cin>>c;
    cout<<c;
   
    
 
   bool p =palindrome(c);
  cout<<p;
    return 0;
}