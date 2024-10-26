/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return mp[root->val] = 1 + max(height(root->left), height(root->right));
    }

    map<int, set<pair<int,int>>> levelnodes; // Changed to 'map' for ordering

    unordered_map<int, int> levelmap;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans;

        height(root);

        queue<TreeNode*> q;

        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto temp = q.front();
                q.pop();

                levelnodes[level].insert({mp[temp->val], temp->val});
                levelmap[temp->val] = level;

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            level++;
        }

        for (auto it : queries) {
            int l = levelmap[it];
            auto& jt = levelnodes[l];

            int maxlevel = 0;

            // Temporarily remove the queried node from the set
            jt.erase({mp[it], it});

            // Find the maximum remaining height at this level after removal
            if (!jt.empty()) {
                maxlevel = jt.rbegin()->first; // Get the maximum remaining height
            }

            // Reinsert the queried node (restore the original state)
            jt.insert({mp[it], it});

            ans.push_back(l + maxlevel-1);
        }

        return ans;
    }
};
