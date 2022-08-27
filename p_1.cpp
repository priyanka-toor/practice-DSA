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
Node
// Node*  takeInput_better(){  // time complexity of that function is O(n)
//    int data;
//    cin>>data;
//    Node *head=NULL;
//    Node *tail=NULL;
//    while(data!=-1) {
//    Node *newNode =new Node(data);
//    if(head==NULL){
//        head =newNode;
//        tail=newNode;
//    }
//    else{
//       tail->next=newNode;
//       tail=tail->next; 
//       //or
//       //tail=newNode;
//    }
//     cin>>data;
//    }
  
//    return head;
// }
// void print(Node *head){
//     while (head!=NULL)
//     {
//         cout<<head->data<<" ";
//         head=head->next;
//     }
    
// }
int main()
{
    // Node *head=takeInput_better();
    // print(head);
    Node *n1 = new Node(1);
    Node *n2=new Node(2);
    Node *n3=new Node(3);
    Node *n4=new Node(4);
    Node *n5=new Node(5);
    int a[5];
    a[0]=n1;
    a[1]=n2;
    a[2]=n3;
    a[3]=n4;
    a[4]=n5;
    return 0;
}