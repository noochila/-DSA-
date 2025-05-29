/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
    pair<int,int> solve(Node* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }
        
        auto left=solve(root->left);
        auto right=solve(root->right);
        
        if(left.first==right.first)
        return {left.first+1,root->data+max(left.second,right.second)};
        else if(left.first<right.first)
        return {right.first+1,root->data+right.second};
        else
        return {left.first+1,root->data+left.second};
    }
    
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
       
       return solve(root).second;
        
        
    }
};