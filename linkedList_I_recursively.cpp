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
Node* insertNode(Node *head, int i, int data) {
	if(head==NULL){
        return head;
    }
    Node *newNode=new Node(data);
    if(i==0){
      newNode->next=head;
        head=newNode;
       return head;
    }
    Node *a=head;
    Node *temp=insertNode(head->next,i-1,data);
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
    int data;
    cin>>data;
   head= insertNode(head , i,data);
    print(head);
    return 0;
}