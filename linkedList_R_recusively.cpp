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
Node *reverseLL(Node *head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node *r=reverseLL(head->next);
    Node *temp=r;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //when we come out from that loop then temp contain the address of last node 
    temp->next=head;
    head->next=NULL;
    return r;
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
    head=reverseLL(head);
    print(head);
    return 0;
}