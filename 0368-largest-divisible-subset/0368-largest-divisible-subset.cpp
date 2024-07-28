class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        // Sort the input array
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> dp(n, 1);  // dp[i] will be the length of the largest divisible subset ending with nums[i]
        vector<int> prev(n, -1);  // prev[i] will track the previous element in the subset ending with nums[i]
        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> result;
        for (int i = maxIndex; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
