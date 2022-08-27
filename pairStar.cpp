#include<iostream>
#include<string.h>
using namespace std;
void star(char c[]){
if(c[0]=='\0'){
    return;
}
int l=strlen(c);
if(c[0]==c[1]){
   // c[1]='*';
    for (int i = l + 1; i > 1; i--)
    {
      c[i] = c[i - 1];
    }
     c[1]='*';
    star(c);
}
else
star(c+1);
}
int main()
{
  char c[50];
  cin >> c;
  star(c);
  cout << c;
    return 0;
}