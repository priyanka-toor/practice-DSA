#include<iostream>
#include<climits>
using namespace std;
class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    stackUsingArray(){
        data=new int[capacity];
        nextIndex=0;
        capacity=4;
    }
    // return the number of elements present in my stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    // insert element
    void push(int element){
          if(nextIndex==capacity){
         int *newData=new int[2*capacity];
         for(int i=0;i<capacity;i++){
             newData[i]=data[i];
         }
         capacity=2*capacity;
         delete[] data;// we are delalocating data array mean delete data array so that new values of data array can enter
        data=newData;
     }
     data[nextIndex]=element;
     nextIndex++;
    }
    // delete element
   int pop(){
       if(isEmpty()){
           cout<<"stack is underflow"<<endl;
           return INT_MIN; // just an indication that stack is empty
       }
       nextIndex--;
       return data[nextIndex];
   }
   // get topmost element 
   int top(){
       if(isEmpty()){
           cout<<"stack is underflow"<<endl;
       }
       return data[nextIndex-1];
   }
};
int main()
{
    stackUsingArray s1;
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
    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;

    return 0;
}