class Solution {
public:
    TreeNode* solve(string &s, int &ind, int depth) {
        int j = ind;
        int d = 0;

       
        while (j < s.size() && s[j] == '-') {
            d++;
            j++;
        }

       
        if (d != depth) return nullptr;

   
        int val = 0;
        while (j < s.size() && isdigit(s[j])) {
            val = val * 10 + (s[j] - '0');
            j++;
        }

       
        TreeNode* node = new TreeNode(val);
        ind = j; 

       
        node->left = solve(s, ind, depth + 1);
        node->right = solve(s, ind, depth + 1);

        return node;
    }

    TreeNode* recoverFromPreorder(string s) {
        int ind = 0;
        return solve(s, ind, 0);
    }
};
