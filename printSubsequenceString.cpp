#include<iostream>
#include<string.h>
using namespace std;
void print_Subs(string i  , string o){
    if(i.length()==0){
        cout<<o<<endl;
        return;
    }
    print_Subs(i.substr(1),o);
    print_Subs(i.substr(1),o+i[0]);
}
int main()
{
    string s;
    cin>>s;
    string o=" ";
    print_Subs(s,o);
    
    return 0;
}