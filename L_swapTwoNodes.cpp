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
Node *swapNodes(Node *head, int i, int j){
    Node *p1 , *c1,*p2,*c2;
    p1=head;
    p2=head;
    int count1=0;
    while(p1!=NULL&&count1<i-1){
        p1=p1->next;
        count1++;
    }
    c1=p1->next;
    int count2=0;
    while(p2!=NULL&&count2<j-1){
        p2=p2->next;
       count2++;
    }
   c2=p2->next;
   if(i==0||j==0){
       c1=p1;
       p1=c2;
       p2->next=c1;
       Node *e=c2->next;
       c2->next=p1->next;
       c1->next=e;
   }
   else if(j-i==1){
       p1->next=c2;
        Node *e=c2->next;
       c2->next=c1;
       c1->next=e;
   }
   else if((i==0&&j==1)||(j==0&&i==1)){
      head=c2;
      Node *e=c2->next;
      c2->next=p1;
      p1->next=e;
   }
   else{
       p1->next=c2;
       p2->next=c1;
       c1->next=c2->next;
       c2->next=p2;
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
    int i,j;
    cin>>i>>j;
    head=swapNodes(head ,i,j);
    print(head);
    return 0;
}