#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // Create a 3D DP array
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Initialize the base cases
        for (int i = 0; i <= 2; ++i) {
            dp[0][0][i] = 0;
            dp[0][1][i] = INT_MIN;
        }
        
        // Fill the DP array
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k <= 2; ++k) {
                dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k] + prices[i-1]);
                dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k-1] - prices[i-1]);
            }
        }

        // The maximum profit with at most two transactions
        return dp[n][0][2];
    }
};
