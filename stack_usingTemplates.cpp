#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class stackUsingArray{
    T *data;
    int nextIndex;
    int capacity;
    public:
    stackUsingArray(){
        data=new T[capacity];
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
    void push(T element){
          if(nextIndex==capacity){
         T *newData=new  T[2*capacity];
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
   T pop(){
       if(isEmpty()){
           cout<<"stack is underflow"<<endl;
           return 0; // just an indication that stack is empty
       }
       nextIndex--;
       return data[nextIndex];
   }
   // get topmost element 
   T top(){
       if(isEmpty()){
           cout<<"stack is underflow"<<endl;
           return 0;
       }
       return data[nextIndex-1];
   }
};
int main()
{
    stackUsingArray<char> s1;
    s1.push(100);
    s1.push(101);
    s1.push(102);
    s1.push(103);
    s1.push(104);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
     cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;

    return 0;
}