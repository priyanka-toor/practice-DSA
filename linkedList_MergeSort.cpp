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
Node* findMid(Node* head){
    Node* fast=head;
    Node* slow=head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next; 
        slow=slow->next;
    }
    
    return slow;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node* finalHead=NULL;
    Node* finalTail=NULL;
    
    
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(finalHead==NULL){
                finalHead=head1;
                finalTail=head1;              
            }
            else{
                finalTail->next=head1;
                finalTail=head1;
            }
                head1=head1->next;

        }
        else{
            if(finalHead==NULL){
                finalHead=head2;
                finalTail=head2;
            }
            else{
                finalTail->next=head2;
                finalTail=head2;
            } 
                head2=head2->next;
        }
    }
    
    if(head1!=NULL){
        finalTail->next=head1;
    }
    if(head2!=NULL){
        finalTail->next=head2;
    }
    return finalHead;

}

Node* mergeSort(Node *head) {
   
    if(head==NULL || head->next==NULL){
        return head;
    }
    
    Node* mid=findMid(head);
    Node* half1=head;
    Node* half2=mid->next;
    
    mid->next=NULL;
    
    half1=mergeSort(half1);
    half2=mergeSort(half2);
    
    head=mergeTwoLLs(half1,half2);
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
    head=mergeSort(head);
    print(head);
    return 0;
}