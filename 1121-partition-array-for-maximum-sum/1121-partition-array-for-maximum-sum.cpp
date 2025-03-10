class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxi = arr[i - 1];
            int limit = k;

            for (int j = i; j >= 1 && limit-- > 0; j--) {
                maxi = max(maxi, arr[j - 1]);
                dp[i] = max(dp[i], dp[j - 1] + maxi * (i - j + 1));
            }
        }

        return dp[n];
    }
};