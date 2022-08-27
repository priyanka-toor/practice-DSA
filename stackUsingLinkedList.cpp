#include<iostream>
using namespace std;
template <typename T>
class Node{
public:
T data;
Node<T> *next;
Node(T data){
    this->data=data;
    next=NULL;
}
};
template <typename T>
class Stack{
  Node<T> *head;
  int size;
  public:
  Stack(){
      head=NULL; 
      size=0;
  }
  int getSize(){
      return size;
  }
  bool isEmpty(){
      return head==NULL;
  }
  void push(T d){
      Node<T> *newNode=new Node<T>(d);
      if(head==NULL){
          head=newNode;
      }
      else{
          newNode->next=head;
          head=newNode;
      }
      size++;
  }
  T pop(){
      if(isEmpty()){
          cout<<"stack is empty"<<endl;
          return 0;
      }
     T a=head->data;
   
     head=head->next;
     size--;
     return a;
  }
  T top(){
      if(isEmpty()){
          cout<<"stack is empty"<<endl;
          return 0;
      }
    return head->data;  
  }
};
int main()
{
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
     cout<<s1.top()<<endl;
    cout<<s1.getSize()<<endl;
    cout<<s1.isEmpty()<<endl;

    return 0;
}