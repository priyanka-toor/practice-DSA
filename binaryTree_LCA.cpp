#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int getLCA(BinaryTreeNode <int>* root , int a, int b,int c){
     if(root==NULL){
        return -1;
    }
    if(a==root->data||b==root->data||c==root->data){
        return root->data;
    }
    int l=getLCA(root->left,a,b,c);
    int r=getLCA(root->right,a,b,c);
    if(l==-1){
        return r;
    }
    else if(r==-1){
        return l;
    }
    else{
        return root->data;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b,c;
    cin >> a >> b>>c;
    cout << getLCA(root, a, b,c);
    delete root;
}