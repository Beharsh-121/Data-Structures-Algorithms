#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
//Fields for the class
      char data;
      TrieNode* children[26];
      bool isTerminal;

//Constructor for the TrieNode
      TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++) children[i] = NULL;
        isTerminal = false;
      }
};

class Trie{
  public:
  TrieNode* root;

  Trie(){
    root = new TrieNode('\0');
  }
  
  void insertUtil(TrieNode* root, string word){
//Base Case
      if(word.length() == 0){
        root->isTerminal = true;
        return;
      }
//Assumption, word will be in Uppercase
      int index = word[0] - 'A';
      TrieNode* child;

      if(root->children[index] != NULL){
        child = root->children[index];
      }else{
        child = new TrieNode(word[0]);
        root->children[index] = child;
      }
//Recursive call
      insertUtil(child, word.substr(1));
  }

  void insertWord(string word){
      insertUtil(root, word);
  }

  bool searchUtil(TrieNode* root, string word){
//Base case
      if(word.length() == 0){
        return root->isTerminal;
      }

      int index = word[0] - 'A';
      TrieNode* child;

      if(root -> children[index] != NULL){
        child = root->children[index];
      }else{
        return false;
      }

      return searchUtil(child, word.substr(1));
  }


  bool searchWord(string word){
      return searchUtil(root, word);
  }

  void removeUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=false;
            cout<<"removed the word"<<endl;
            return; 
        }
        int index=word[0]-'A';
        TrieNode* child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            return;
        }
        removeUtil(child,word.substr(1));
    }
    void removeWord(string word){
        if(searchWord(word) == false){
            cout<<"already absent"<<endl;
        }
        else{
            removeUtil(root,word);
        }
    }

};

int main(){
    Trie *t = new Trie();
    
    t->insertWord("ABCD");
    cout << "Present or not" << t->searchWord("ABCD") << endl;
    t->removeWord("ABCD");
    cout << "Present or not" << t->searchWord("ABCD") << endl;

    return 0;
}