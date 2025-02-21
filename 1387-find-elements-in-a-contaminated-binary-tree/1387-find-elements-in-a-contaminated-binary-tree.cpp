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
class FindElements {
public:
    TreeNode* head;
    FindElements(TreeNode* root) {

        head = root;

        if (root != nullptr)
            root->val = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            if (temp->left) {
                int val = temp->val * 2 + 1;
                temp->left->val = val;
                q.push(temp->left);
            }

            if (temp->right) {
                int val = temp->val * 2 + 2;
                temp->right->val = val;
                q.push(temp->right);
            }
        }
    }

    bool find(int target) { return solve( head, target); }

    bool solve(TreeNode* root, int target) {
        if (root == nullptr)
            return false;

        if (root->val == target)
            return true;

        return solve(root->left, target) || solve(root->right, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */