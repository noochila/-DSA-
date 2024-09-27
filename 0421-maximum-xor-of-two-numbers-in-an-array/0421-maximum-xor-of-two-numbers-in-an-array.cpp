struct Node {
    Node* link[2] = {nullptr, nullptr};
};

class Trie {

private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(int num) {
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (curr->link[bit] == nullptr) {
                curr->link[bit] = new Node();
            }
            curr = curr->link[bit];
        }
    }

    int getMax(int num) {
        int maxNum = 0;
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1; 

            if (curr->link[1 - bit] != nullptr) {
                maxNum |= (1 << i); 
                curr = curr->link[1 - bit];
            } else {
                curr = curr->link[bit];
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        
      
        for (auto it : nums) {
            trie->insert(it);
        }

        int maxi = 0;
        
        
        for (auto it : nums) {
            maxi = max(maxi, trie->getMax(it));
        }
        
        return maxi;
    }
};
