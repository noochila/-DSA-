#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        vector<int> temp(n + 2, 0);

        // Copy the nums array into the temp array
        for (int i = 0; i < n; i++)
            temp[i + 1] = nums[i];

        temp[0] = temp[n + 1] = 1;

        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    int currCoins = temp[i - 1] * temp[k] * temp[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], currCoins);
                }
            }
        }

        return dp[1][n];
    }
};
