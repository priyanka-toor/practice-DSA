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
Node *appendLastNToFirst(Node *head, int n){
 if(head==NULL || n==0)return head;
    int l=length(head);
    Node* temp=head;
    int count=1;

   while(count<l-n){
       temp=temp->next;
       count++;
   }
   Node *h=temp->next;
    temp->next=NULL;
    Node*p=h;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=head;
  

   return h;
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
    int n;
    cin>>n;
   head=appendLastNToFirst(head,n);
   print(head);
    return 0;
}