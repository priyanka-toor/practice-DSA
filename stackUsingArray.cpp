#include<iostream>
#include<climits>
using namespace std;
class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    stackUsingArray(int totalSize){
        data=new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    // return the number of elements present in my stack
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
      /*  if(nextIndex==0){
            return true;
        }
        else
        false;*/
        return nextIndex==0;
    }
    // insert element
    void push(int element){
          if(nextIndex==capacity){
         cout<<"stack is overflow"<<endl;
         return;
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
    stackUsingArray s1(4);
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