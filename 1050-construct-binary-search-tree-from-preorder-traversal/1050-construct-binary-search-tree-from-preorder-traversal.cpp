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
  TreeNode* buildtree(int in[], int pre[], int n) {
        if (n == 0)
            return nullptr;

        int rootind = 0;
        while (rootind < n && in[rootind] != pre[0])
            rootind++;

        TreeNode* root = new TreeNode(pre[0]);

        TreeNode* leftsubtree = buildtree(in, pre + 1, rootind);
        TreeNode* rightsubtree = buildtree(in + rootind + 1, pre + rootind + 1, n - rootind - 1);

        root->left = leftsubtree;
        root->right = rightsubtree;

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        if (n == 0)
            return nullptr;

        int preorder1[n];
        int inorder1[n];

        for (int i = 0; i < n; i++) {
            preorder1[i] = preorder[i];
            inorder1[i] = inorder[i];
        }

        return buildtree(inorder1, preorder1, n);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {


        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());

        return buildTree(preorder,inorder);


        
    }
};