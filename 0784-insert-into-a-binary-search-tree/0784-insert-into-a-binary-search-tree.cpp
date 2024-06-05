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
    void solve(TreeNode* root, int val) {
      

        if (root == nullptr) {
            return;
        }

        

        if (root->val > val && root->left) {
            cout << root->val << endl;
            solve(root->left, val);
        } else if (root->val <= val && root->right) {
            cout << root->val << endl;
            solve(root->right, val);
        }
        if (root->val > val && !root->left) {
            cout << "came" << endl;
            root->left = new TreeNode(val);
            return;
        } else if (root->val <= val && !root->right) {
            cout << "not came" << endl;
            root->right = new TreeNode(val);
            return;
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

       if(root==nullptr)
       return new TreeNode(val);

        solve(root, val);
        return root;
    }
};