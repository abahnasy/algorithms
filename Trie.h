//
// Created by Ahmed Bahnasy on 14.08.20.
//

#ifndef ALGORITHMS_TRIE_H
#define ALGORITHMS_TRIE_H

#include <string>

using namespace std;

const int ALPHABET_SIZE  = 26;

struct TrieNode {
    TrieNode* descendants[ALPHABET_SIZE];
    bool end;
};

TrieNode* generate_node(void) {
    TrieNode* node = new TrieNode();
    node->end = false;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        node->descendants[i] = nullptr;
    }
    return node;
}

void add (TrieNode* root, string s) {
    TrieNode* current = root;
    for (char c : s) {
        int idx = c - 'a';
        if(!current->descendants[idx]) {
            TrieNode* node = generate_node();
            current->descendants[idx] = node;
        }
        current = current->descendants[idx];
    }
    //mark the last node as end of valid word
    current->end = true;
}

bool find (TrieNode* root, string s) {
    TrieNode* current = root;
    for (char c: s){
        int idx = c - 'a';
        if(!current->descendants[idx])
            return false;
        current = current->descendants[idx];
    }
    // check if last letter represents valid word and the root is not equal null
    return ((current!= nullptr) && (current->end== true));
}





#endif //ALGORITHMS_TRIE_H
