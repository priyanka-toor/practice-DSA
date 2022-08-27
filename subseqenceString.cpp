#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int subs(string s , string a[]){
if(s.empty()){        // mean string has no element in it and it has only one row
  a[0]=" ";  // empty string 
  return 1;
}
string smallString=s.substr(1);
//cout<<smallString<<endl;
int smallOutputsize=subs(smallString , a);
cout<<smallOutputsize<<endl;
for(int i=0;i<smallOutputsize;i++){
    a[i+smallOutputsize]=s[0]+a[i];
}
return 2*smallOutputsize;
}
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int m=pow(2,n);
    string* a=new string[m];
    int count=subs(s,a);
    for(int i = 0;i<count;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}