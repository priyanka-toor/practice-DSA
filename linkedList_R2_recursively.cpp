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
/*class pair{
    public:
    Node *head;
    Node *tail;
};

pair reverseLL_2(Node *head){
    if(head==NULL||head->next==NULL){
        pair ans;
        ans.head=head;
        ans.tail=ans;
        return ans;
    }
    pair *r=reverseLL_2(head->next);
   r.tail->next=head;
   head->next=NULL;
   pair ans;
   ans.head=r.head;
   ans.tail=head;
   return ans;
}
Node *reverseLL_better(Node *head){
    return  reverseLL_2(head).head;
}*/

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
class pair{
    public:
    Node *head;
    Node *tail;
};

pair reverseLL_2(Node *head){
    if(head==NULL||head->next==NULL){
        pair ans;
        ans.head=head;
        ans.tail=ans;
        return ans;
    }
    pair *r=reverseLL_2(head->next);
   r.tail->next=head;
   head->next=NULL;
   pair ans;
   ans.head=r.head;
   ans.tail=head;
   return ans;
}
Node *reverseLL_better(Node *head){
    return  reverseLL_2(head).head;
}
/*Node *reverseLL_better(Node *head){
    return  reverseLL_2(head).head;
}
pair reverseLL_2(Node *head){
    if(head==NULL||head->next==NULL){
        pair ans;
        ans.head=head;
        ans.tail=ans;
        return ans;
    }
    pair *r=reverseLL_2(head->next);
   r.tail->next=head;
   head->next=NULL;
   pair ans;
   ans.head=r.head;
   ans.tail=head;
   return ans;
}*/
// Node *reverseLL_better(Node *head){
//     return  reverseLL_2(head).head;
// }
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
    head =reverseLL_better(head);
    print(head);
    return 0;
}