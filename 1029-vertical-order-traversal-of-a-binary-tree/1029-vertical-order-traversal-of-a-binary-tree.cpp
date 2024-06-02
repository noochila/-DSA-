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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

         map<int, vector<pair<int, int>>> nodes;
        
        // queue to perform BFS
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int x = temp.second.first;
            int y = temp.second.second;
            TreeNode* node = temp.first;
            
            nodes[x].push_back({y, node->val});
            
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        
        // iterate over the map and sort nodes within each group
        for (auto it : nodes) {
            sort(it.second.begin(), it.second.end());
            vector<int> col;
            for (auto p : it.second) {
                col.push_back(p.second);
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};