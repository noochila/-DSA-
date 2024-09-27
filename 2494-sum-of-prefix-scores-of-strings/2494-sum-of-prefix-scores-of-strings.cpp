#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool endWord;
    TrieNode* link[26];
    int count = 1;
};

class Trie {

public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {

        TrieNode* curr = root;
        cout<<word<<endl;

        for (int i = 0; i < word.size(); i++) {
            if (curr->link[word[i] - 'a'] == nullptr) {
                curr->link[word[i] - 'a'] = new TrieNode();
                curr = curr->link[word[i] - 'a'];
                // cout<<word[i]<<" "<<curr->count<<endl;

                
            } else {
               
                curr = curr->link[word[i] - 'a'];
                 curr->count++;
                // cout<<word[i]<<" "<<curr->count<<endl;
            }
        }
        curr->endWord = true;
    }

    int search(string word) {

        TrieNode* curr = root;
        int c = 0;

        for (int i = 0; i < word.size(); i++) {
            // cout<<word<<endl;
            if (curr->link[word[i] - 'a'] == nullptr) {

                return c;
            } else {
                // cout<<word[i]<<" "<<curr->count<<endl;
                curr = curr->link[word[i] - 'a'];
                c += curr->count;
            }
        }

        return c;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {

        Trie* trie = new Trie();

        for (auto it : words) {
            trie->insert(it);
        }

        vector<int> ans;

        for (auto it : words) {
            ans.push_back(trie->search(it));
        }

        return ans;
    }
};