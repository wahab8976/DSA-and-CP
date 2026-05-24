
/*
Unlike, Tries - I Which return true or false, this particular code returns counts
*/

#include"../bits/stdc++.h"

class Node {
public:
    Node* links[26];
    int endsWith;
    int startsWith;

    Node() {
        this->endsWith = 0;
        this->startsWith = 0;
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(Node* node, char ch) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void incrementEnd() {
        this->endsWith++;
    }

    void decrementEnd() {
        this->endsWith--;
    }

    void incrementPrefix() {
        this->startsWith++;
    }

    void decrementPrefix() {
        this->startsWith--;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        this->root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(new Node(), word[i]);
            }
            node = node->get(word[i]);
            node->incrementPrefix(); // Track how many words pass through this character
        }
        node->incrementEnd();
    }

    int countWordsEqualTo(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->endsWith;
    }

    int countWordsStartingWith(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->startsWith; // Returns the total count of words sharing this prefix
    }

    void erase(string word) {
        // First check if the word actually exists to prevent decreasing counts incorrectly
        if (countWordsEqualTo(word) == 0) return; 

        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            Node* nextNode = node->get(word[i]);
            nextNode->decrementPrefix();
            
            // If no other words use this path, delete the node
            if (nextNode->startsWith == 0) {
                node->links[word[i] - 'a'] = NULL;
                delete nextNode;
                return; // Since we deleted the rest of the path, we can stop early
            }
            
            node = nextNode;
        }
        node->decrementEnd();
    }
};