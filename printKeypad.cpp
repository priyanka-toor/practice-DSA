#include<iostream>
#include<string.h>
using namespace std;
string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void print_keypad(int n , string o){
   
 if(n==0){
        cout<<o<<endl;
        return;
    }
   string k=key[n%10];
   for(int i=0;i<k.size();i++){
       print_keypad(n/10 , k[i]+o);

   }
}
void print(int num){
    string o=" ";
    print_keypad(num,o);
}
int main()
{
       int num;
    cin >> num;

    print(num);
    return 0;
}