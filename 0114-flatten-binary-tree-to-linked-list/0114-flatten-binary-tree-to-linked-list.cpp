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


  void solve(TreeNode* root,TreeNode* &prev)
  {
    if(root==nullptr)
    return ;

    solve(root->right,prev);
    solve(root->left,prev);

    root->right=prev;
    root->left=nullptr;
    prev=root;


  }
    void flatten(TreeNode* root) {


        // TreeNode* prev=nullptr;

        // solve(root,prev);
         if (root == nullptr) return;

        // stack<TreeNode* >s;

        // s.push(root);
        // while(!s.empty())
        // {
        //     TreeNode* temp=s.top();
        //     s.pop();

        //     if(temp->right)
        //     s.push(temp->right);
        //     if(temp->left)
        //     s.push(temp->left);

        //     if(!s.empty())
        //     temp->right=s.top();

        //     temp->left=nullptr;
        // }



        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left)
            {
                TreeNode* next=curr->left;
                while(next->right)
                next=next->right;


                next->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;


            }
            curr=curr->right;

        }


        
    }
};