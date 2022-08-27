#include<iostream>
#include<string.h>
using namespace std;
void x(char c[]){
    
    int l = strlen(c);
if(c[0]=='\0'){
    return;
}
if(c[0]=='x'){
   

  for(int i=0;i<l;i++){
       c[i]=c[i+1];
}
x(c);
} 
x(c+1);
}
int main(){
 char c[50];
  cin >> c;
 
  x(c);
  cout << c;
    return 0;
}