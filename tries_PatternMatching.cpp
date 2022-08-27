#include<iostream>
using namespace std;
#include <string>
#include <vector>

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
bool search(TrieNode *root, string word){
        if(word.size()==0){
            if(root->isTerminal==true){
                return true;
            }
            else
            return false;
        }
        int index=word[0]-'a';
        bool b;
        TrieNode *child;
         if(root->children[index]==NULL){
            return false;
        }
        else{
            child=root->children[index];
             b=search(child,word.substr(1));
        }
      
        return b;
    }
    bool search(string word){
     return search(root,word);
    }
    bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
        for(int i=0;i<vect.size();i++){
            string s=vect[i];
            int n=s.size();
            int k=n;
            for(int j=0;j<n;j++){
                insertWord(s);
                insertWord(s.substr(0,k-1));
                s=s.substr(1);
                k--;
            }
        }

        return search(pattern);
    }
};
int main()
{
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
    return 0;
}