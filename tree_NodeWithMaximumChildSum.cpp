#include<iostream>
using namespace std;
#include<vector>
#include<queue>
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
template <typename T>
class Pair{
    public:
    TreeNode<T> *node;
    T sum;
};
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
           cin>>childData;
       TreeNode<int> *child=new TreeNode<int>(childData);
       front->children.push_back(child);
       pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int> *root){
     queue<TreeNode<int>*> pendingNodes;
     pendingNodes.push(root);
     while(pendingNodes.size()!=0){
         TreeNode<int> *front=pendingNodes.front();
         pendingNodes.pop();
        cout<<root->data<<":"; 
     
     for(int i=0;i<root->children.size();i++){
         cout<<root->children[i]->data<<",";
         pendingNodes.push(root->children[i]);
     }
     root=pendingNodes.front();
     cout<<endl;
     }
}
Pair<int>* greaterSum(TreeNode<int>* root){
     Pair<int> *ans = new Pair<int>();
    Pair<int> *x = new Pair<int>();
   x->sum=root->data;
    x->node=root;
    if(root->children.size()==0)
        return x;
   for(int i=0;i<root->children.size();i++){
     x->sum=x->sum+root->children[i]->data;
    } 

    for(int i=0;i<root->children.size();i++){
       ans=greaterSum(root->children[i]);
       if(x->sum>ans->sum){
           ans->sum=x->sum;
           ans->node=x->node;
       }
    }
    
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root){
 
    return greaterSum(root)->node;
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
   // printTree(root);                                
   printLevelWise(root);
   TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
    return 0;
}