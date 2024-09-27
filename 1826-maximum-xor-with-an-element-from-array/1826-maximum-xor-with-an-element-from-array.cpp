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
            } else if (curr->link[bit] != nullptr) {
                curr = curr->link[bit];
            } else {
                return -1; 
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        Trie* trie = new Trie();

        vector<int> ans(queries.size());
        sort(nums.begin(), nums.end());

        vector<pair<int, pair<int, int>>> modifiedQueries;

        for (int i = 0; i < queries.size(); i++) {
            modifiedQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(modifiedQueries.begin(), modifiedQueries.end());

        auto it = nums.begin();

        for (int i = 0; i < modifiedQueries.size(); i++) {
            while (it != nums.end() && *it <= modifiedQueries[i].first) {
                trie->insert(*it);
                it++;
            }

           if (it == nums.begin()) {
              
                ans[modifiedQueries[i].second.second] = -1;
            } else {
                ans[modifiedQueries[i].second.second] = trie->getMax(modifiedQueries[i].second.first);
            }
        }

        return ans;
    }
};