#include<iostream>
using namespace std;
int main(){
 /*   char ch = 'a';
 char* ptr = &ch;
 cout << *ptr << endl;
 cout <<ch<< endl;
 cout<<ptr<<endl;
 ch++;
 cout << *ptr << endl;
 cout <<ch<< endl;*/
 char b[] = "xyz";
char *c =b;
cout<<*(c+1)<<endl;
cout << c[0] << endl;
cout << b[0] << endl;
c++;
cout << c << endl;
cout << b << endl;
}