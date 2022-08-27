#include<iostream>
using namespace std;
#include<stack>
#include<string.h>
bool isBalanced(string e){
    stack<char> s;
  for(int i=0;i<e.size();i++){
     if (e[i] == '(' || e[i] == '{' || e[i] == '['){
          s.push(e[i]);
      }
    else  if(e[i] == ')'){
          if(!s.empty() && s.top() == '('){
              s.pop();
          }
      }
      else  if(e[i] == '}'){
          if(!s.empty() && s.top() == '{'){
              s.pop();
          }
      }
      else  if(e[i] == ']'){
          if(!s.empty() && s.top() == '['){
              s.pop();
          }
      }
  }
  return s.empty();
}
int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
    return 0;
}