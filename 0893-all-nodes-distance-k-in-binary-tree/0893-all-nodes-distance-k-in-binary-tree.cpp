#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;

    void buildParentMap(TreeNode* root, TreeNode* parent) {
        if (root == nullptr)
            return;

        parentMap[root] = parent;

        buildParentMap(root->left, root);
        buildParentMap(root->right, root);
    }

    void findNodesAtDistanceK(TreeNode* root, int k, unordered_set<TreeNode*>& visited, vector<int>& result) {
        if (root == nullptr || visited.find(root) != visited.end())
            return;

        visited.insert(root);

        if (k == 0) {
            result.push_back(root->val);
            return;
        }

        findNodesAtDistanceK(root->left, k - 1, visited, result);
        findNodesAtDistanceK(root->right, k - 1, visited, result);
        findNodesAtDistanceK(parentMap[root], k - 1, visited, result);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if (root == nullptr || target == nullptr)
            return result;

        // Build the parent map
        buildParentMap(root, nullptr);

        // To keep track of visited nodes
        unordered_set<TreeNode*> visited;

        // Find all nodes at distance k from target
        findNodesAtDistanceK(target, k, visited, result);

        return result;
    }
};
