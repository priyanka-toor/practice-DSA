#include<iostream>
using namespace std;
int main(){
   /* while (true)
    {
      int *p=new int;
    }
     while (true)
    {
      int i=10;
    }*/
    int *p=new int;
    *p=10;
    cout<<*p<<endl;
    delete p;  // single element deletion
     cout<<*p;
    int *pa=new int[50]; // array deletion
    delete [] pa;

    
}