#include<iostream>
using namespace std;
#include<stack>
#include<string.h>
int countBracketReversals(string e){
    if(e.size()%2!=0){
        return -1;
    }
    stack<char> s;
    int count=0;
    for(int i=0;i<e.size();i++){
        if(e[i]=='{'){
          s.push('{');
      }
        if(s.empty()&&e[i]=='}'){
            s.push('}');
        }
      else if(!s.empty()&&s.top()=='{'&&e[i]=='}'){
         	s.pop();
            
      }
      else if(!s.empty()&&s.top()!='{'){
          s.push('}');
      }
    }
      while(!s.empty()){
          char c1=s.top();
          cout<<c1<<endl;
          s.pop();
          char c2=s.top();
          cout<<c2<<endl;
          s.pop();
         if(c1==c2){
             count++;
         }
         if(c1!=c2){
             count=count+2;
         }
      }
   
    return count;

}
int main()
{
     string input;
    cin >> input;
    cout << countBracketReversals(input);
    return 0;
}