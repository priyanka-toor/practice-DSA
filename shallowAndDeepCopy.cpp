#include<iostream>
#include<string.h>
using namespace std;
class student{
    int age;
    char *name;
    public:
    student(int age , char *name){
        this->age=age;
        //shallow copy mean copy the reference of an array or copy the address of first element of an array
      // this->name=name;
      // deep copy mean whole array 
      this->name=new char[strlen(name)+1];// +1 for null character
      strcpy(this->name,name);
    }
    void display(){
        cout<<age<<endl<<name<<endl;
    }
};
int main()
{ 
    char name[]="abcd";

    student s1(20,name);
    name[3]='e';
    student s2(21,name);
    s1.display();
    s2.display();
    s1.display();

    return 0;
}