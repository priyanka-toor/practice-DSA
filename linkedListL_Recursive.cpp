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
int length(Node *head){
    Node* temp=head;
    if(temp==NULL){
        return 0;
    }
   int l=length(temp->next);
   return l+1;
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
    int l=length(head);
    cout<<l;
    return 0;
}