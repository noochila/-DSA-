class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, 
                              vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }

        int nodeval = postorder[postEnd];
        TreeNode* node = new TreeNode(nodeval);

        int inorderIndex = inStart;
        while (inorderIndex <= inEnd && inorder[inorderIndex] != nodeval) {
            inorderIndex++;
        }

        int leftTreeSize = inorderIndex - inStart;

        node->left = buildTreeHelper(inorder, inStart, inorderIndex - 1, 
                                     postorder, postStart, postStart + leftTreeSize - 1);

        node->right = buildTreeHelper(inorder, inorderIndex + 1, inEnd, 
                                      postorder, postStart + leftTreeSize, postEnd - 1);

        return node;
    }
};
