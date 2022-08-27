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
Node*  takeInput(){
   int data;
   cin>>data;
   Node *head=NULL;
   while(data!=-1) {
  // Node n(data);  ----> we can't do this because here we declared Node object as statically and if we declare statically the whole node is deleted after completing one loop but when we declare it dynamically node can't be deleted untill it is done by us.
  // dynamically
   Node *newNode =new Node(data);
   if(head==NULL){
       // head =&n; ----> when it declared as statically
       head =newNode;
   }
   else{
       Node *temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=newNode;
   }
    cin>>data;
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
    Node *head=takeInput();
    print(head);
    return 0;
}