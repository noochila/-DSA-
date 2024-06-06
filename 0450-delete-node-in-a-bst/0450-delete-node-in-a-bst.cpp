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
TreeNode* inorderSuccessor(TreeNode*root)
{  
    if(root==nullptr)
    return nullptr;

    while(root->left!=nullptr)
    root=root->left;

    return root;
}

TreeNode* deleteN(TreeNode* root,int key)
{
      if(root==nullptr)
        return nullptr;

        if(root->left==nullptr && root->right==nullptr && root->val==key)
        {
            delete(root);
            return nullptr;
        }

        if(root->val>key)
        {
            root->left= deleteN(root->left,key);
        }else if(root->val<key)
        {
            root->right= deleteN(root->right,key);
        }else
        {
            auto temp=inorderSuccessor(root->right);
            if(temp==nullptr)
            {
                auto temp=root->left;
                delete(root);
                return temp;
            }

            root->val=temp->val;
            root->right= deleteN(root->right,temp->val);
            
        }

        return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {


      return deleteN(root,key);
        
     

    }
};