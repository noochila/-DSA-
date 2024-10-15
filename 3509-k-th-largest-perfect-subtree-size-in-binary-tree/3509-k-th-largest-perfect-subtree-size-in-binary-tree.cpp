class Solution {
public:
    vector<int> heights;

    pair<int, int> height(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        auto left = height(root->left);
        auto right = height(root->right);

        if (left.first == right.first) {
            int expectedNodes = pow(2, left.first + 1) - 1;
            int actualNodes = left.second + right.second + 1;
            if (expectedNodes == actualNodes) {
                heights.push_back(expectedNodes);
            }
        }

        return {1 + max(left.first, right.first), left.second + right.second + 1};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        height(root);

        sort(heights.begin(), heights.end(), greater<int>());

        if (k - 1 < 0 || k > heights.size())
            return -1;

        return heights[k - 1];
    }
};
