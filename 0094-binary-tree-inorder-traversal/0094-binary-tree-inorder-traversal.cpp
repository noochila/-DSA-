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
          vector<int> result;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                
                while (pre->right != nullptr) {
                    pre = pre->right;
                }
                
                pre->right = curr;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = nullptr;
            }
        }

        return result;
    }
};