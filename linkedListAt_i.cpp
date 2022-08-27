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
void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}
void printIthNode(Node *head,int i){
    Node *curr=head;
    int count=0;
    
    while(count<i&&curr!=NULL){
        curr=curr->next;
        // count++;
     if(curr==NULL) return;
    count++;
    }
    

    cout<<curr->data;

}
int main()
{
    Node *head=takeInput_better();
    print(head);
    cout<<endl;
    int pos;
	cin >> pos;
	printIthNode(head, pos);
    return 0;
}