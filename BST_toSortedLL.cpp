#include<iostream>
using namespace std;
#include<queue>
template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
class Base{
public:
Node<int>*head;    
Node<int>*tail;
    
    Base()
    {
       head=NULL;
        tail=NULL;
    }

};
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>* takeInputLevelWise(){
     int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!=-1){
          BinaryTreeNode<int>* child=new BinaryTreeNode<int>(leftChildData);
          front->left=child;
          pendingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
         int rightChildData;
        cin>>rightChildData;
        if(rightChildData!=-1){
          BinaryTreeNode<int>* child=new BinaryTreeNode<int>(rightChildData);
          front->right=child;
          pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root){
   queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
       BinaryTreeNode<int> *front=pendingNodes.front();
       cout<<front->data<<":";
       pendingNodes.pop();
      if(front->left!=NULL){
      cout<<"L"<<front->left->data<<",";
        pendingNodes.push(front->left);
      }
      else{
          cout<<"L:-1,";
      }
       if(front->right!=NULL){
        cout<<"R:"<<front->right->data;
        pendingNodes.push(front->right);
       }
       else{
           cout<<"R:-1";
       }
        cout<<endl;
    }
}
Base helperfunction(BinaryTreeNode<int>*root)
{
Base combinedlist;
    if(root==NULL)
    {
return combinedlist;}
    Base leftlist=helperfunction(root->left);
    Node<int>*newNode =new Node<int>(root->data);
    Base rightlist=helperfunction(root->right);
    if(leftlist.tail!=NULL)
    {
leftlist.tail->next=newNode;
    }
    newNode->next=rightlist.head;
    if(leftlist.head!=NULL)
    {
combinedlist.head=leftlist.head;
    }
    else{
combinedlist.head=newNode;
    }
    if(rightlist.tail!=NULL)
    {
combinedlist.tail=rightlist.tail;
    }
    else{
combinedlist.tail=newNode;
    }
    return combinedlist;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root){
   Base list=helperfunction(root);
    return list.head;

}
int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
     Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    delete root;
    return 0;
}