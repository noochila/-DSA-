class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 3, 1e9);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for (int k = 4; k <= n; k++) {
            for (int i = 1; i * i <= k; i++) {
                int square = i * i;
                if (k - square >= 0) {
                    dp[k] = min(dp[k], 1 + dp[k - square]);
                }
            }
        }

        return dp[n];
    }
};
