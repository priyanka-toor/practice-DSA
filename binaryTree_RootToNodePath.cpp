#include<iostream>
using namespace std;
#include<queue>
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
vector<int>* getRootToNodePath(BinaryTreeNode<int> *root,int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
       vector<int>* output=new vector<int>();
       output->push_back(root->data);
       return output;
    }
    vector<int>* leftOutput=getRootToNodePath(root->left,data);
    if(leftOutput!=NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
     vector<int>* rightOutput=getRootToNodePath(root->right,data);
    if(rightOutput!=NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}
int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    vector<int>* output=getRootToNodePath(root,7);
    for(int i=0;i<output->size();i++){
        cout<<output->at(i)<<endl;
    }
    delete root;
    delete output;
    return 0;
}
//1 2   3   4   5   6   7   -1  -1  -1  -1  8   9   -1  -1  -1  -1  -1  -1