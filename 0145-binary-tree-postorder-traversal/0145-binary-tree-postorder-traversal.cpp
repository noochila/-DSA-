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
    vector<int> postorderTraversal(TreeNode* root) {
        //  stack<TreeNode*>s1,s2;
        //   vector<int > ans;
        //   if(root==NULL)
        //   return ans;

        //  s1.push(root);
        //  while(!s1.empty())
        //  {
        //      root=s1.top();
        //      s1.pop();
        //      s2.push(root);
        //      if(root->left!=NULL)
        //      s1.push(root->left);
        //      if(root->right!=NULL)
        //      s1.push(root->right);
        //  }

        //  while(!s2.empty())
        //  {
        //      ans.push_back(s2.top()->val);
        //      s2.pop();
        //  }

        //  return ans;


        vector<int>ans;
        stack<TreeNode*>s;
       

        while(!s.empty() || root!=nullptr)
        {

            if(root!=nullptr)
            {
                s.push(root);
                root=root->left;
            }else
            {
                TreeNode* temp=s.top()->right;

                if(temp==nullptr)
                {
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);

                    while(!s.empty() && s.top()->right==temp)
                    {
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }

                }else
                {
                    root=temp;
                }
            }

            

        }

        return ans;
         
        
    }
};