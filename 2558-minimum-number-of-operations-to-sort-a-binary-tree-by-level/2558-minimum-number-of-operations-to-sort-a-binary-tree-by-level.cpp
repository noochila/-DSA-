#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minSwaps(vector<int>& arr, int N) {
        int ans = 0;
        vector<pair<int, int>> temp(N);
        for (int i = 0; i < N; i++) {
            temp[i] = {arr[i], i};
        }
        sort(temp.begin(), temp.end());
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++) {
            if (visited[i] || temp[i].second == i) continue;
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = temp[j].second;
                cycle_size++;
            }
            if (cycle_size > 1) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }

    int minimumOperations(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            while (size--) {
                auto t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            ans += minSwaps(temp, temp.size());
        }
        return ans;
    }
};
