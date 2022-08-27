#include<iostream>
using namespace std;
class Deque{
    int *data;
  int front;
  int rear;
  int capacity;
  int size;
  public:
  Deque(int totalSize){
   data=new int[totalSize];
   front=-1;
   rear=0;
   capacity=totalSize;
   size=0;
  }
  int getSize(){
      return size;
  }
   bool isEmpty(){
   return size==0;
 }
  void insertFront(int element){
    if(size==capacity){
      cout<<-1;
      return;
    }
    front=0;
    data[front]=element;
    size++;
 }
 void insertRear(int element){
      if(size==capacity){
      cout<<-1;
      return;
    }
    rear=size;
    data[rear]=element;
 }
 void deleteFront(){
   if(isEmpty()){
     cout<<-1;
     return;
   }
      int a=data[front];
      front++;
      size--;
 }
 void deleteRear(){
    if(isEmpty()){
     cout<<-1;
     return;
   }
   int a=data[rear];
   size--;
 }
 int getFront(){
    if(isEmpty()){
  
   return -1;
 }
   return data[front];
 }
  int getRear(){
   if(isEmpty()){
   return -1;
 }
   return data[rear];
 }

 
};
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}