/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {


        unordered_map<int,TreeNode*> mp;

        unordered_set<int>s;

        for(auto it:descriptions)
        {
            int parent=it[0];
            int child=it[1];
            bool left=it[2];

            if(mp.find(parent)==mp.end())
            {
                mp[parent]=new TreeNode(parent);
            }

            if(mp.find(child)==mp.end())
            {
                mp[child]=new TreeNode(child);
            }


            if(left)
            {
                mp[parent]->left=mp[child];
            }else
            {
                mp[parent]->right=mp[child];
            }

            s.insert(child);
        }


        for(auto it:descriptions)
        {
            if(s.find(it[0])==s.end())
            return mp[it[0]];

        }

    return nullptr;
        


    }
};