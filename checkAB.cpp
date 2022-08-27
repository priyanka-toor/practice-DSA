#include<iostream>
#include<string.h>
using namespace std;

bool checkAB(char i[]){
    if(i[0]=='\0'){
    return false;
}
if(i[0]=='b'){
        return false;
    }
    if(i[0]=='a' && i[1]=='\0'){
    return true;
    }
if(i[0]=='a'){
    if(i[1]=='b'&&i[2]=='b'&&i[3]!='b'){
        return true;
    }
}
bool b=checkAB(i+1);
return b;
}
 
int main()
{
     char i[100];
     
    bool ans;
    cin >> i;
    ans=checkAB(i);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
    return 0;
}