/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class BSTIterator
{
public:
    stack<TreeNode *> s;
    bool reverse; // reverse is true means it's before else it's next

    BSTIterator(TreeNode *root, bool reverse)
    {
        this->reverse = reverse;
        pushALL(root);
    }

    int next()
    {
        TreeNode *temp = s.top();
        if (!reverse)
        {

            s.pop();
            pushALL(temp->right);
        }
        else
        {

            s.pop();
            pushALL(temp->left);
        }

        return temp->val;
    }

    bool hasNext()
    {

        return !s.empty();
    }

    void pushALL(TreeNode *root)
    {
        if (!reverse)
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
        }
        else
        {
            while (root)
            {
                s.push(root);
                root = root->right;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(root==nullptr)
        return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i=l.next(),j=r.next();

    while(i<j)
    {
        int sum=i+j;
        if(sum==k)
        return true;
        else if(sum<k)
        {
            i=l.next();
        }else
        j=r.next();
    }

    return false;


  


    }
};