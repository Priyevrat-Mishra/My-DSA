#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
public:
    TrieNode *child[26];
    bool isLeaf;
    TrieNode(){
        isLeaf = false;
        for(int i=0; i<26;i ++)
            child[i] = NULL;
    }
};

class Trie{
    TrieNode *root;
public:
    Trie(){
        root= new TrieNode();
    }

    void insert(string word){
        TrieNode *node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isLeaf = true;
    }

    bool search(string word){
        TrieNode *node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node->child[idx] == NULL)    
                return false;
            node = node->child[idx];
        }
        return node->isLeaf;
    }

};

int main(){
    Trie *tree = new Trie();
    tree->insert("apple");
    tree->insert("appex");
    tree->insert("map");
    cout <<"Does It Exist : " << tree->search("apple");


    return 0;
}