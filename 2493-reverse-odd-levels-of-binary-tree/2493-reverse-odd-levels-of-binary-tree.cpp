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

    void solve(TreeNode* left,int level,TreeNode* right)
    {

        if(left==nullptr || right==nullptr)
        return ;

        if(level%2 )
        
            swap(left->val,right->val);

        

        solve(left->left,level+1,right->right);
        solve(left->right,level+1,right->left);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {

        solve(root->left,1,root->right);

        return root;
        

    }
};