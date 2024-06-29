class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<unordered_map<int, int>> dp(n);

        int result = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];
                if (diff < INT_MIN || diff > INT_MAX) continue;
                int d = (int)diff;

                dp[i][d] += 1;
                if (dp[j].find(d) != dp[j].end()) {
                    dp[i][d] += dp[j][d];
                    result += dp[j][d];
                }
            }
        }

        return result;
    }
};