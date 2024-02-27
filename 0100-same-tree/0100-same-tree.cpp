class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p != nullptr && q != nullptr) {
            cout<<p->val<<" "<<q->val<<endl;
            if (p->val == q->val) {
                bool val1 = solve(p->left, q->left);
                bool val2 = solve(p->right, q->right);
                
                return val1 && val2;
            } else {
                return false;
            }
        } else {
            // One of p or q is null, but not both
            return false;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
