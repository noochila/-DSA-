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

class BSTIteratorleft {
public:
    stack<TreeNode*> s;
    BSTIteratorleft(TreeNode* root) { pushALL(root); }

    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushALL(temp->right);
        return temp->val;
    }

    bool hasNext() { return !s.empty(); }

    void pushALL(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};
class BSTIteratorright {
public:
    stack<TreeNode*> s;
    BSTIteratorright(TreeNode* root) { pushALL(root); }

    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushALL(temp->left);
        return temp->val;
    }

    bool hasNext() { return !s.empty(); }

    void pushALL(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        if(root==nullptr)
        return false;
    BSTIteratorleft l(root);
    BSTIteratorright r(root);

    for(int i=l.next(),j=r.next();i<j;)
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