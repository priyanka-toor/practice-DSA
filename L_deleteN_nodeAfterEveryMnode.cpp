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
Node *skipMdeleteN(Node *head, int m, int n){
    if(m==0){
        return NULL;
    }
  Node *t1=head;
  while(t1){
    int  c1=1;
      while(c1!=m&&t1!=NULL){
          t1=t1->next;
          c1++;
      }
      if(t1==NULL){
          return head;
      }
    Node *t2=t1->next;
     int c2=1;
      while(c2<=n&&t2!=NULL){  //to delalocate last t2 we have to iterate c2 upto n mean c2<=n
          Node *d=t2;
          t2=t2->next;
          free(d);
          c2++;
      }
      t1->next=t2;
     t1=t2;
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
    int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
    return 0;
}