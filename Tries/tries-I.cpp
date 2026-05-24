// Also known as Prefix Tree

#include"../bits/stdc++.h"

class Node{
    public:
    Node* links[26];
    bool flag;

    Node(){
        this->flag = false;
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch)
    {
        if(links[ch - 'a'] == NULL) return false;
        return true;
    }

    void put(Node* node,char ch){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        this->flag = true;
    }

    bool isEnd(){
        return this->flag;
    }
};

class Trie {
private:
    Node* root; 
public:
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i = 0; i < word.size();i++){
            // If no node exist, add one
            if(!node->containsKey(word[i])){
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]); // Go to newly attached Node
        }
        node->setEnd(); // Set Last node to be true
    }
    
    bool search(string word) {
        Node* node = root;

        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])) return false;   // Check if key exist 
            node = node->get(word[i]);  // Traverse to referenced Node
        }

        // If end is true, means node is found
        if(node->isEnd() == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;

        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return false;   // Check if key exist 
            node = node->get(prefix[i]);
        }
        // If we reached till end, the word exists in the tree
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */