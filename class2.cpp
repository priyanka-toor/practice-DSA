#include<iostream>
using namespace std;
class student{
   public:
 int rollNo;

 int age;
 public:
 ~student(){  //destructor is called
 cout<<"Destructor is called "<<endl;
 }
 student(){
cout<<"Constructor is called "<<endl;
 }
 // parametrized constructor
 student(int r){
     cout<<"constructor with argument is called"<<endl;
     rollNo=r;
 }
 student(int rollNo , int age){
     cout<<"constructor with two arguments "<<endl;
     cout<<"this : "<<this<<endl;
     this->rollNo=rollNo;
     this->age= age;
 }
 public:
 void display(){
     cout<<rollNo<<" "<<age<<endl;
 }
 void setAge(int a){
     age=a;
 }
  int getAge(){
      return age;
  }
 };
 int main(){
   /*  student s1(20, 21);
     student s2(s1);
     s1.display();
     s2.display();
     student *s3=new student(10,20);
     s3->display();
     student s4(*s3);
     s4.display();
     student *s5=new student(*s3);
     s5->display();
     student *s6=new student(s1);
     s6->display();*/
     // copy assignment opertor
     student s7(1,19);
     student s8(2,20);
     s8.display();
     s8=s7;  // copy assignment operator
     s8.display();
      student *s3=new student(10,20); // for this destructor is not because s3 is dynamically allocated 
     s3->display();
     delete s3;  // to call destructor for s3 we use delete keyword
 }
