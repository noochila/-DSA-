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

   int solve(TreeNode* root)
   {
    if(root==nullptr)
    return 0;
    else if(root->left==nullptr && root->right==nullptr)
    return 1;

    return solve(root->left)+solve(root->right)+1;

     
   }
    int countNodes(TreeNode* root) {




        return solve(root);

        
        
    }
};