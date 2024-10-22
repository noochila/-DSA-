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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        queue<TreeNode*>q;

        q.push(root);

        vector<long long> ans;


        while(!q.empty())
        {
         
            int size=q.size();
            long long count=0;
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                 if(temp!=nullptr)
                count+=temp->val;

                if(temp->left)
                q.push(temp->left);

                if(temp->right)
                q.push(temp->right);
                
            }

            ans.push_back(count);
        }

        sort(ans.begin(),ans.end(),greater<>());
        // cout<<ans.size()<<endl;

        if(ans.size()<(k))
        return -1;

        return ans[k-1];
        
    }
};