// trie.h
#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
    int frequency = 0;
};

class Trie {
private:
    TrieNode* root;

public:
    Trie();
    void insert(const string& word, int frequency);
    TrieNode* searchPrefix(const string& prefix);
    void collectWords(TrieNode* node, string prefix, vector<pair<string, int>>& results);
};

#endif