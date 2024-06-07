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

TreeNode* first,*middle,*prev,*last;

  void inorder(TreeNode* root)
   {
       if(root==nullptr)
       return ;

       inorder(root->left);

       if(prev!=nullptr && (root->val<prev->val))
       {
           if(first==nullptr)
           {
            first=prev;
            middle=root;
           }else 
           {
             
             last=root;
           }
       }

       prev=root;
       inorder(root->right);

   }

    void recoverTree(TreeNode* root) {


        first=middle=last=nullptr;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        
        if(first!=nullptr && last!=nullptr)
        {
            swap(first->val,last->val);
        }
        else if(first!=nullptr && middle!=nullptr)
        {
            swap(first->val,middle->val);
        }


    }
};