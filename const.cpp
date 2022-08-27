#include<iostream>
using namespace std;

int main()
{
   /* int j=10;
    const int &k=j;
    j++;
   //k++;
    cout<<k<<endl;
    const int a=20;
  //  int &b=a;
    const int c=10;
    //int *p=&c;
    int const *p=&c;
   // cout<<*(p++);
    int d=10;
    int const *pd=&d;
  //  d++;
   // cout<<d<<endl;
    
    cout<<*pd<<endl;
    int x=*(pd)++;
    cout<<x<<endl;*/
    int i=10;
    int j=20;
    int const *p=&i;  // it means that jiski taraf main point kar rha hun wo constant
    p=&j;
    cout<<*p<<endl;
    int *const pi=&i; // isme pointer khud hi constant hai
   // pi=&j; so we can't do here that
   int  const *const p3=&i;// here p3 is const pointer point to a constant inetger

    return 0;
}