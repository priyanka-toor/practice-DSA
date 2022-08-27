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
class Custom{
    public:
    TreeNode<T>* max;
    TreeNode<T>* S_max;
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
Custom<int>* getTwoLargest(TreeNode<int> *root){
Custom<int> *ans=new Custom<int>();
Custom<int> *temp=new Custom<int>();
Custom<int> *discard=new Custom<int>();
ans->max=root;
ans->S_max=NULL;
for(int i=0;i<root->children.size();i++){
    ans->S_max=root->children[i];
temp=getTwoLargest(root->children[i]);
//temp->S_max=root->children[i];
if(temp->max!=NULL&&temp->max->data>ans->max->data){
    ans->max=temp->max;
}
else if(discard->max!=NULL&&discard->max->data>ans->max->data){
    ans->max=discard->max;
}
else{
 discard->max=temp->max;
}
if(temp->S_max!=NULL&&temp->S_max->data>ans->S_max->data){
    ans->S_max=temp->S_max;
}
else if(discard->S_max!=NULL&&discard->S_max->data>ans->S_max->data){
    ans->S_max=discard->S_max;
}
else{
   // discard->max=temp->max;
    discard->S_max=temp->S_max;
}
if(ans->S_max&&ans->S_max->data>ans->max->data){
    ans->S_max=ans->max;
}
}
return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root){
  return getTwoLargest(root)->S_max;
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
   // printTree(root);                                
 //  printLevelWise(root);
    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
    return 0;
}