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
    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        vector<int> levelSum;

       

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            while (size--) {
                auto temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }
            levelSum.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto temp = q.front();
                q.pop();

                int siblingSum = (temp->left ? temp->left->val : 0) +
                                 (temp->right ? temp->right->val : 0);

                if (temp->left) {
                    temp->left->val = levelSum[level] - siblingSum;
                    q.push(temp->left);
                }
                if (temp->right) {
                    temp->right->val = levelSum[level] - siblingSum;
                    q.push(temp->right);
                }
            }
            level++;
        }

        return root;
    }
};