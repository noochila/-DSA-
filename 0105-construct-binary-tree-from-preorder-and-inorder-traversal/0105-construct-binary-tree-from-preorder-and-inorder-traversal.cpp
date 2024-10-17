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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        int nodeval = preorder[preStart];
        TreeNode* node = new TreeNode(nodeval);

        int inorderIndex = inStart;
        while (inorderIndex <= inEnd && inorder[inorderIndex] != nodeval) {
            inorderIndex++;
        }

        int leftTreeSize = inorderIndex - inStart;

        node->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, 
                                     inorder, inStart, inorderIndex - 1);

        node->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, 
                                      inorder, inorderIndex + 1, inEnd);

        return node;
    }
};
