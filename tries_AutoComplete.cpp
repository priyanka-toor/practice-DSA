#include<iostream>
using namespace std;
#include<string>
#include<vector>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
TrieNode* search(TrieNode *root, string word){
        if(word.size()==0){
         /*   if(root->isTerminal==true){
                return root;
            }
            else
            return NULL;*/
            return root;
        }
        int index=word[0]-'a';
        TrieNode *b;
        TrieNode *child;
         if(root->children[index]==NULL){
            return NULL;
        }
        else{
            child=root->children[index];
             b=search(child,word.substr(1));
        }
      
        return b;
    }
    TrieNode* search(string word){
     return search(root,word);
    }
    void allPossibleWord(TrieNode *r,string pattern, vector<char> output){

       if(r->isTerminal==true&&output.size()!=0){
           cout<<pattern;
               for(int j=0;j<output.size();j++){
                   cout<<output[j];
               }
               cout<<endl;
       }
       for(int i=0;i<26;i++){
          
           if(r->children[i]!=NULL){
               output.push_back(i+'a');
              allPossibleWord(r->children[i],pattern,output);
              output.pop_back();
           }
           }
           output.pop_back();
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        int n= input.size();
        for(int i=0;i<n;i++){
            insertWord(input[i]);
        }
        TrieNode *r=search(pattern);
        cout<<r->data;
         vector<char> output;
       if(r!=NULL){
        if(r->isTerminal==true){
        cout<<pattern<<endl;
        }
       
        allPossibleWord(r,pattern,output);
         }
    }
};
int main()
{
   Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);  
    return 0;
}