#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        vector<unordered_map<int, int>> mp(52);
        vector<multiset<int>> st(52);
        vector<vector<int>> dp(n+2, vector<int>(k+2, 1));

        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 0; j--) {
                int op1 = mp[j][nums[i]] + 1;
                int op2 = 0;

                if (j != 0) {
                    int rm = mp[j-1][nums[i]];
                    if (rm != 0) {
                        int len = st[j-1].size();
                        if (len >= 2) {
                            auto it = st[j-1].rbegin();
                            op2 = *it;

                            if (op2 == rm) {
                                it++;
                                if (it != st[j-1].rend()) {
                                    op2 = *it;
                                } else {
                                    op2 = 0; // No valid second largest value
                                }
                            }

                        }
                    } else {
                        int len = st[j-1].size();
                        if (len != 0) {
                            auto it = st[j-1].rbegin();
                            op2 = *it;
                        }
                    }
                }

                dp[i][j] = max(op2 + 1, op1);
                mp[j][nums[i]] = dp[i][j];
                st[j].insert(dp[i][j]);
            }
        }

        int g = 0;
        for (int i = 0; i <= n - 1; i++) {
            int u = dp[i][k];
            g = max(g, u);
        }

        return g;
    }
};
