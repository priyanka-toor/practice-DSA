#include<iostream>
using namespace std;
int len(char c[]){
    if(c[0]=='\0'){
        return 0;
    }
    int l=len(c+1);
    return l+1;
}
int main()
{
    char c[50];
  cin >> c;
  int l=len(c);
cout<<l;
    return 0;
}