#include <iostream>
#include <string>
using namespace std;
int returnPermutations(string a , string o[]){
if(a.length()==0){
    o[0]=" ";
    return 1;
}
string o1[1000] , o2[1000];
for(int i=0;i<a.length();i++){
    o1[i]=a[i+1];
}
for(int i=0;i<a.length();i++){
    o2[i]=a[a.length()-i];
}
}
int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}