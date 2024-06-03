/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <queue>
#include <algorithm>
#define ll long long

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        ll maxi = 0;
        std::queue<std::pair<TreeNode*, ll>> q;
        q.push({root, 0});

        while (!q.empty()) {
            ll size = q.size();
            ll minIndex = q.front().second;  // Use the index of the first node to normalize indices
            ll first, last;
            for (ll i = 0; i < size; ++i) {
                ll curIndex = q.front().second - minIndex;  // Normalize to prevent overflow
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;

                if (node->left) q.push({node->left, 2 * curIndex + 1});
                if (node->right) q.push({node->right, 2 * curIndex + 2});
            }
            maxi = std::max(maxi, last - first + 1);
        }

        return maxi;
    }
};
