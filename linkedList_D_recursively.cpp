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
Node *deleteNodeRec(Node *head, int pos) {
    if(head==NULL){
        return head;
    }
    if(pos==0){
        head=head->next;
        return head;
    }
    Node *a=head;
    Node *temp=deleteNodeRec(head->next,pos-1);
    a->next=temp;
    return a;
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
    head=deleteNodeRec(head,i);
    print(head);
    return 0;
}