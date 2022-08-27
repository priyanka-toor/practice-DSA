#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> q;
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    vector<Node<int>*> output;
    q.push(root);
    //q.push(NULL);
    while(q.empty()){
       BinaryTreeNode<int> *c=q.front();
     
       q.pop();
     if(!q.empty()&&c!=NULL){
           q.push(NULL);
       }
     
     // if(c!=NULL)
     while(q.front()!=NULL)
       {
      Node<int> *curr=new Node<int>(c->data);
       q.push(c->left);
       q.push(c->right);
           if(head==NULL){
               head=curr;
               tail=curr;
           }
         else{
               tail->next=curr;;
              tail=tail->next; 
           }
       }
       if(c==NULL){
           output.push_back(head);
       }
       head=NULL;
       tail=NULL;
      
    }
    return output;
}
void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}