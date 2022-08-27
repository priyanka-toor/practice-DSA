#include<iostream>
using namespace std;
#include<string>
#include<cstring>
#include<unordered_map>
#include<vector>
string uniqueChar(string str){
    string s;
    unordered_map<char,bool> seen;
    int j=0;
    for(int i=0;i<str.length();i++){
        if(seen.count(str[i])>0){
        
            continue;
        }
        seen[str[i]]=true;
      s.push_back(str[i]);
    }
    return s;
}
int main()
{
      string str;
    cin >> str;
    cout << uniqueChar(str);
    return 0;
}