// autocomplete.cpp
#include "trie.h"
#include <queue>
#include <string>
using namespace std;

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const string& word, int frequency) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isEndOfWord = true;
    node->frequency = frequency;
}

TrieNode* Trie::searchPrefix(const string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (node->children.find(c) == node->children.end()) {
            return nullptr;
        }
        node = node->children[c];
    }
    return node;
}

void Trie::collectWords(TrieNode* node, string prefix, vector<pair<string, int>>& results) {
    if (!node) return;
    if (node->isEndOfWord) {
        results.push_back({prefix, node->frequency});
    }

    for (auto& entry : node->children) {
        collectWords(entry.second, prefix + entry.first, results);
    }
}
