#include<iostream>
using namespace std;

int main()
{
/* int *ptr = 0;
int a = 10;
//*ptr = a;
 cout << *ptr << endl;*/
/* int a = 7;
int *c = &a;
c = c + 1;
cout  << a << "  " << *c << endl;*/
int a[10];
cout<<"a = "<<a<<endl;
cout<<"&a ="<<&a<<endl;
a[0]=5;
a[1]=10;
cout<<"*a = "<<*a<<endl;
cout<<"*(a+1) = "<<*(a+1)<<endl;
int *p=a;
cout<<p[1]<<endl;
cout<<*p<<endl;

cout<<"a = "<<a<<endl;
cout<<"p = "<<p<<endl;
cout<<"&p ="<<&p<<endl;
cout<<"&a ="<<&a<<endl;
cout<<"sizeof(p) : "<<sizeof(p)<<endl;
cout<<"sizeof(a) : "<<sizeof(a)<<endl;
// a=a+1    a can't be reassigned
cout<<"(a+1) "<<(a+1)<<endl;
}
