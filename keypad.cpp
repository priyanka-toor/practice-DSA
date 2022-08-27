#include<iostream>
using namespace std;

string key[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    
    if(num==0){
       output[0]="";
        return 1;
    }
    string o[500];
    int smallSize=keypad(num/10,o);
    // cout<<smallSize<<endl;
    // num=num%10;
    string k=key[num%10];
    int count=0;
    for(int j=0;j<smallSize;j++){
    for(int i=0;i<k.size();i++){
        output[count++]=o[j]+k[i];
    }
    }
    return count;

}

int main()
{
      int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}