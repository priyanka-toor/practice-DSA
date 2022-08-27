// better than linkedList2.cpp 
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int data){
    this->data=data;
    next=NULL;
}
};
Node*  takeInput_better(){  // time complexity of that function is O(n)
   int data;
   cin>>data;
   Node *head=NULL;
   Node *tail=NULL;
   while(data!=-1) {
   Node *newNode =new Node(data);
   if(head==NULL){
       head =newNode;
       tail=newNode;
   }
   else{
      tail->next=newNode;
      tail=tail->next; 
      //or
      //tail=newNode;
   }
    cin>>data;
   }
  
   return head;
}
int length(Node* head){
    int count=0;
    while(head!=NULL){
     head=head->next;
     count++;
    }
    return count;
}
Node *removeDuplicates(Node *head){
 
  Node *t1=head;
  
 while(t1!=NULL){
      Node *t2=t1->next;
     while(t2!=NULL&&t1->data==t2->data){
       t2=t2->next;
     }
       t1->next=t2;  
       t1=t2;
       if(t2!=NULL)
           t2=t2->next;
 
 }
 return head;
}
void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
int main()
{
    Node *head=takeInput_better();
    print(head);
    head=removeDuplicates(head);
    print(head);
    return 0;
}