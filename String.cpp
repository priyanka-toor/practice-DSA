#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string s1="abc";
    string s2="def";
    string s3=s1+s2;   // concatinate two strings s1 and s2
    cout<<s3<<endl;
    s3+=s1;
    cout<<s3<<endl;
    cout<<s3.size()<<endl;
    cout<<s3.substr(3)<<endl;  // give string form index 3
    cout<<s3.substr(4,3)<<endl; // give string form index 4 upto  next element of length 3
    cout<<s3.find("def")<<endl;
    return 0;
}