#include<iostream>
#include<string.h>
using namespace std;
void rd(char *c){
    int l=strlen(c);
    if(c[0]=='\0'){
        return;
    }
    if(c[0]==c[1]){
        for(int i=0;i<l;i++){
            c[i]=c[i+1];
        }
        rd(c);
    }
   // else
    rd(c+1);
}
int main()
{
    char c[50];
    cin >> c;
    rd(c);
    cout<<c;
    return 0;
}