class Solution {
public:
    int solve(vector<int>& prices, int buy, int ind, vector<vector<int>>& dp) {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + solve(prices, 0, ind + 1, dp), solve(prices, 1, ind + 1, dp));
        } else {
            // Option to sell or skip
            profit = max(prices[ind] + solve(prices, 1, ind + 2, dp), solve(prices, 0, ind + 1, dp));
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1)); // Correct dp initialization
        return solve(prices, 1, 0, dp); // Initialize with buy state
    }
};
