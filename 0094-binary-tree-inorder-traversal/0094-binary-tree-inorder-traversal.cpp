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
    vector<int> inorder(TreeNode* root) {
        if (root == nullptr)
            return {};

        stack<TreeNode*> s;

        vector<int> ans;

        while (true) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            }

            else {
                if (s.empty())
                    break;
                ans.push_back(s.top()->val);
                auto temp = s.top();
                s.pop();
                root = temp->right;
            }
        }

        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {

        // return inorder(root);
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor of current
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                // Make current the right child of its inorder predecessor
                if (prev->right == nullptr) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Revert the changes made in the tree structure
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};