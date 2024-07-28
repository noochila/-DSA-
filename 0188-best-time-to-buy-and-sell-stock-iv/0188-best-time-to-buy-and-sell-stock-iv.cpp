class Solution {
public:
    int solve(vector<int>& prices, int buy, int ind, int c,
              vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size() || c == 0)
            return 0;
        if (dp[ind][buy][c] != -1)
            return dp[ind][buy][c];

        int profit = 0;
        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + solve(prices, 0, ind + 1, c, dp),
                         solve(prices, 1, ind + 1, c, dp));
        } else {
            // Option to sell or skip
            profit = max(prices[ind] + solve(prices, 1, ind + 1, c - 1, dp),
                         solve(prices, 0, ind + 1, c, dp));
        }

        return dp[ind][buy][c] = profit;
    }

    int maxProfit(int k, vector<int>& Arr) {
            int n=Arr.size();
         vector<vector<vector<int>>> dp(n + 1,
                                    vector<vector<int>>(2, vector<int>(k + 1, 0)));

    // Loop through the stock prices from the end to the beginning

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap],
                                -Arr[ind] + dp[ind + 1][1][cap]);
                }

                if (buy == 1) { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap],
                                Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    return dp[0][0][k];
    

    }
    };