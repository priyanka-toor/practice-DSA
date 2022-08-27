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
Node *deleteNode(Node *head, int pos){
    Node* temp=head;
    int count=0;
    int l=length(head);
    if(pos>=l){
        return head;
    }
    if(pos==0){
        head=temp->next;
        return head;
    }
    while(temp!=NULL&&count<pos-1){
     temp=temp->next;
     count++;
    }
    if(temp!=NULL){
        Node *a=temp->next;
        Node *b=a->next;
        temp->next=b;
        delete a;
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
    int i;
    cin>>i;
    head=deleteNode(head,i);
    print(head);
    return 0;
}