#include<iostream>
using namespace std;
#include<stack>
#include<string.h>
bool checkRedundantBrackets(string e){
stack<char> s;
int i=0;

int count;   
 while(i<e.size()){
     s.push(e[i]);
 if(s.top()==')'){
     count=-1;
 while(s.top()!='('){
   // s.pop();
    count++;
    s.pop();
}
s.pop();
}
i++;

}
if(!s.empty()){
    return 0;
}
cout<<count<<endl;
return count==0;
}

int main()
{
     string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
    return 0;
}