#include<iostream>
using namespace std;
#include<queue>
#include<stack>
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
void zigZagOrder(BinaryTreeNode<int>* root){
   stack<BinaryTreeNode<int>*> s1;
   stack<BinaryTreeNode<int>*> s2;
   s1.push(root);
   while(s1.size()!=0){
       while(s1.size()!=0){
           BinaryTreeNode<int> *front=s1.top();
           if(front->left!=NULL){
               s2.push(front->left);
           }
           if(front->right!=NULL){
               s2.push(front->right);
           }
           cout<<front->data<<" ";
           s1.pop();
       }
       cout<<endl;
       while(s2.size()!=0){
           BinaryTreeNode<int>* front=s2.top();
            if(front->right!=NULL){
               s1.push(front->right);
           }
            if(front->left!=NULL){
               s1.push(front->left);
           }
           cout<<front->data<<" ";
           s2.pop();
       }
       cout<<endl;
   }
}
int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    zigZagOrder(root);
    delete root;
    return 0;
}
//5 6   10  2   3   -1  -1  -1  -1  -1  9   -1  -1