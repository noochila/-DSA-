
struct TrieNode {
    bool endWord;
    TrieNode* link[26];
    int c = 0;
};

class Trie {

public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {

        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->link[word[i] - 'a'] == nullptr) {
                curr->link[word[i] - 'a'] = new TrieNode();
                curr = curr->link[word[i] - 'a'];
                curr->c++;
            } else {
                curr = curr->link[word[i] - 'a'];
                 curr->c++;
            }
        }

        curr->endWord = true;
    }

    bool search(string word) {

        TrieNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->link[word[i] - 'a'] == nullptr) {

                return false;
            } else {
                curr = curr->link[word[i] - 'a'];
            }
        }

        return true;
    }

    int startsWith(string prefix) {

        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->link[prefix[i] - 'a'] == nullptr) {
                return 0;
            } else {
                curr = curr->link[prefix[i] - 'a'];
            }
        }

        return curr->c;
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        Trie* trie = new Trie();

        for (auto it : words)
            trie->insert(it);

        return trie->startsWith(pref);
    }
};