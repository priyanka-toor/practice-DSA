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
Node *evenAfterOdd(Node *head){
    Node *oddH=NULL;
    Node *oddT=NULL;
    Node *evenH=NULL;
    Node *evenT=NULL;
    while(head!=NULL){
        if((head->data)%2!=0){
            if(oddH==NULL){
                oddH=head;
                oddT=head;
            }
           else
           {
                oddT->next=head;
                oddT=oddT->next;
            }
        }
       else
       {
            if(evenH==NULL){
                evenH=head;
                evenT=head;
            }
           else
           {
                evenT->next=head;
                evenT=evenT->next;
            }
        }
        head=head->next;
    }
    if(oddH==NULL&&oddT==NULL){
        return evenH;
    }
     if(evenH==NULL&&evenT==NULL){
        return oddH;
    }
    oddT->next=evenH;
    evenT->next=NULL;
    return oddH;
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
    head=evenAfterOdd(head);
    print(head);
    return 0;
}