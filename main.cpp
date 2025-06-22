
// main.cpp
#include "trie.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int k = 5;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;  // sort by frequency
}

int main() {
    Trie trie;
    ifstream infile("words.txt");
    string word;
    int freq;

    while (infile >> word >> freq) {
        trie.insert(word, freq);
    }

    string prefix;
    cout << "Enter a prefix: ";
    cin >> prefix;

    TrieNode* node = trie.searchPrefix(prefix);
    if (!node) {
        cout << "No suggestions found.\n";
        return 0;
    }

    vector<pair<string, int>> results;
    trie.collectWords(node, prefix, results);
    sort(results.begin(), results.end(), cmp);

    cout << "Top " << k << " suggestions:\n";
    for (int i = 0; i < min(k, (int)results.size()); i++) {
        cout << results[i].first << " (frequency: " << results[i].second << ")\n";
    }

    return 0;
}