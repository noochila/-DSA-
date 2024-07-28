class Solution {
public:
    int solve(vector<int>& prices, int buy, int ind, int c, vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size() || c == 0)
            return 0;
        if (dp[ind][buy][c] != -1)
            return dp[ind][buy][c];

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + solve(prices, 0, ind + 1, c, dp), solve(prices, 1, ind + 1, c, dp));
        } else {
            // Option to sell or skip
            profit = max(prices[ind] + solve(prices, 1, ind + 1, c - 1, dp), solve(prices, 0, ind + 1, c, dp));
        }

        return dp[ind][buy][c] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1))); // Correct dp initialization
        return solve(prices, 1, 0, 2, dp); // Initialize with 2 transactions allowed
    }
};
