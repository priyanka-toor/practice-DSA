#include<iostream>
using namespace std;
#include "class1.cpp"
int main()
{
     student s1(10 , 20);
   cout<<"ADDRESS OF S1 : "<<&s1<<endl;
   student s2(20, 21);
   cout<<"ADDRESS OF S2 : "<<&s2<<endl;
   s1.display();
   s2.display();
    // s1.age = 20;
    
//    s1.setAge(20);
//      s1.rollNo=1;
//  //   s1.student();
//      s1.display();
//      student *s5=new student;
//     // s5->age=22;
//     s5->setAge(22);
//      s5->rollNo=3;
//      s5->display();
//       student s2(10);
//       s2.display();

//       student *s6=new student(20);
//       s6->display();
//       student *s3=new student(21,20);
//       s3->display();

    return 0;
}