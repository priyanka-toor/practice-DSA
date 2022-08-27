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
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x){
    if(root==NULL){
        return NULL;
    }
    TreeNode<int> *l;
    if(root->data>x){
      l=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *s=l;
        l=getNextLargerElement(root->children[i],x);
        if(l->data>s->data){
            l=s;
        }
       
    }
    return l;
}
int main()
{
    TreeNode<int> *root=takeInputLevelWise();
   // printTree(root);                                
 //  printLevelWise(root);
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
    return 0;
}