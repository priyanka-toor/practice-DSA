#include<iostream>
#include<string.h>
using namespace std;
int convertInt(char a){
    int i=a-'0';
    return i;
}
char convertChar(int i){
    char c='a'+i-1;
    return c;
}
int getCodes(string s , string o[]){
    if(s.length()==0){
        o[0]=" ";
        return 1;
    }
    string r1[30] , r2[30];
int s1=0 , s2=0;
for(int i=0;i<s.length();i++){
    r1[s1++]=convertChar(convertInt(s[i]));
}
int a=getCodes(s.substr(1),r1);
a=s1;
return a;
}
int main()
{
     string input;
    cin >> input;

    string output[30];
    int count = getCodes(input, output);
    for(int i = 0; i < count; i++)
        cout << output[i] << endl;
    return 0;
}