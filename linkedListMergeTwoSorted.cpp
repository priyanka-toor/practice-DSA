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
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
       Node *fh=NULL;
  Node *ft=NULL;
     if(head1->data<=head2->data){
         fh=head1;
         head1=head1->next;
     }
     else{
         fh=head2;
         head2=head2->next;
     }
     ft=fh;
  while(head1!=NULL&&head2!=NULL){
    
      if(head2->data<head1->data){
          ft->next=head2;
          head2=head2->next;
          ft=ft->next;
      }
       if(head1->data<=head2->data){
          ft->next=head1;
          head1=head1->next;
            ft=ft->next;
      }
  }
  if(head1!=NULL){
      ft->next=head1;
  }
  if(head2!=NULL){
      ft->next=head2;
  }
  return fh;
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
    Node *head1=takeInput_better();
    print(head1);
    Node *head2 = takeInput_better();
     
    print(head2);
	Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
    
	print(head3);
    return 0;
}