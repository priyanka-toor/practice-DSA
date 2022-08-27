#include<iostream>
using namespace std;
/*void incrementPointer(int *p){
    p++;
}
void inrement(int *p){
    *p=(*p)*(-1);
}
void fun(int a[]){
    cout<<"f a"<<a[0]<<endl;
}
int main(){
   /* int i=10;
    int *p=&i;
    cout<<p<<endl;
    incrementPointer(p);
    cout<<p<<endl;
    cout<<*p<<" "<<i<<endl;
    inrement(p);
    cout<<*p<<" "<<i<<endl;
    int a[]={1,2,3,4};
    fun(a+1);
    cout<<a[0];*/
   /* int a = 100;
  int *p = &a;
  int **q = &p;
  int b = (**q)++;
  int *r = *q;
  (*r)++;
  cout << a << " " << b << endl;
  int c[]={1,2,3,4};
  int *s=(c+1);
  cout<<*c+8;
  }*/


void swap (char *x, char *y) 
{
  char *t = x;
  x = y;
  y = t;
}

int main()
{
   char *x = "geeksquiz";
   char *y = "geeksforgeeks";
   char *t;
   swap(x, y);
   cout<<x << " "<<y;
   t = x;
   x = y;
   y = t; 
   cout<<" "<<x<< " "<<y;
   return 0;
}


