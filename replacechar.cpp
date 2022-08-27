#include<iostream>
using namespace std;
void replaceChar(char c[] , char c1 , char c2){
    if(c[0]=='\0'){
        return;
    }
    if(c[0]==c1){
        c[0]=c2;
       
    }
    replaceChar(c+1,c1,c2);
}
int main()
{
    char c[50];
  cin >> c;
  char c1 , c2;
  cin>>c1>>c2;
  replaceChar(c,c1,c2);
  cout<<c;
    return 0;
}