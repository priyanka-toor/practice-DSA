#include<iostream>
#include<unordered_map>
using namespace std;
#include<string>
int main()
{
    unordered_map<string,int> ourMap;
    // insert
    pair<string,int> p("abc",1);
    ourMap.insert(p);
    ourMap["def"]=2;
    //find or access
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("def")<<endl;
    //cout<<ourMap.at("ghi")<<endl;
    cout<<"size "<<ourMap.size()<<endl;
    cout<<ourMap["ghi"]<<endl;  
     cout<<"size "<<ourMap.size()<<endl;
    //check presense 
    if(ourMap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    ourMap["abc"]=1;
    cout<<"abc : "<<ourMap.count("abc")<<endl;
    // erase or delete an element 
    ourMap.erase("ghi");
     if(ourMap.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    cout<<"size "<<ourMap.size()<<endl;
    return 0;
}