#include<iostream>
using namespace std;
#include<queue>
#include<vector>
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
// below method is in inorder 
 void getAllValues(BinaryTreeNode<int>* root,int *a){
     static int i=0;
     if(root==NULL){
         return;
     }
    getAllValues(root->left,a);
    a[i++]=root->data;
    getAllValues(root->right,a);
     
 }
 int getSize(BinaryTreeNode<int>* root){
     if(root==NULL){
         return 0;
     }
     else
     return getSize(root->left)+getSize(root->right)+1;
 }// quick sort
 void swap(int a[] , int i ,int j){
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int a[] , int s ,int e){
    int x=a[s];
    int i=s+1;
    int j=e;
    do{
        if(a[i]<=x){
            i++;
        }
        if(a[j]>x){
            j--;
        }
        if(i<=j){
            swap(a,i,j);
        }
        
    }while(i<=j);
    swap(a,s,j);
    return j;
}
void quick_Sort(int input[],int s,int e ){
     int p;
    if(s<e){
         p=partition(input , s ,e);
        quick_Sort(input , s, p-1);
        quick_Sort(input , p+1,e);
    }
    else
        return;
}      
void pairSum(BinaryTreeNode<int> *root, int sum){
    int n=getSize(root);
    int *a=new int[n];
    getAllValues(root,a);
     quick_Sort(a, 0, n - 1);
   for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int i=0;
    int j=n-1;
    while(i<j){
        int s=a[i]+a[j];
        if(s==sum){
            cout<<a[i]<<" "<<a[j]<<endl;
            i++;
            j--;
        }
        else if(s>sum){
            j--;
        }
        else if(s<sum){
            i++;
        }
    }
}
int main()
{
    BinaryTreeNode<int>* root=takeInputLevelWise();
    printLevelWise(root);
    int sum;
    cin>>sum;
    pairSum(root,sum);
    delete root;
    return 0;
}