#include<iostream>
using namespace std;
class student{
   public:
 int rollNo;
 private:
 int age;
 public:
 student(){
cout<<"Constructor is called "<<endl;
 }
 // parametrized constructor
 student(int r){
     cout<<"constructor with argument is called"<<endl;
     rollNo=r;
 }
 student(int rollNo , int age){
     cout<<"this : "<<this<<endl;
     this->rollNo=rollNo;
     this->age= age;
 }
 public:
 void display(){
     cout<<rollNo<<" "<<age<<endl;
 }
 int getAge(){
     return age;
 }
 int setAge(int a){
     age=a;
 }
 
};
