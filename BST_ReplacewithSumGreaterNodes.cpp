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
int getSum(BinaryTreeNode<int>* root,int sum){
    if(root==NULL){
        return sum;
    }
     int rightSum=getSum(root->right,sum);
     root->data=rightSum+root->data;
     sum=root->data;
    int leftSum=getSum(root->left,sum);
    sum=leftSum;
    return sum;
}
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root){
    int sum=getSum(root,0);
    printLevelATNewLine(root);

}
int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    replaceWithLargerNodesSum(root);
    delete root;
    return 0;
}