#include<iostream>
using namespace std;
#include<string>
#include<vector>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
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
    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        int n=words.size();
        for(int i=0;i<n;i++){
            add(words[i]);
        }
        for(int i=0;i<n;i++){
           string rev = string(words[i].rbegin(), words[i].rend());
           cout<<rev;
            bool b=search(rev);
            if(b==true){
                return true;
            }
             else{
                int k=rev.size();
                for(int j=0;j<rev.size();j++){
                    bool c=search(rev.substr(0,k-1));
                    bool d=search(rev.substr(j));
                    k--;
                    if(c==true){
                        return true;
                    }
                    if(d==true){
                        return true;
                    }
                }
             }
        }
        return false;
    }
};
int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
    
    return 0;
}