class Solution {
public:
    vector<int> windowsum;
    vector<vector<int>> dp;

    int helper(int count, int idx, int k) {
        if (count == 0) return 0;
        if (idx >= windowsum.size()) return INT_MIN;

        if (dp[idx][count] != -1) return dp[idx][count];

        int take = windowsum[idx] + helper(count - 1, idx + k, k);
        int ntake = helper(count, idx + 1, k);

        return dp[idx][count] = max(take, ntake);
    }

    void solve(int count, int idx, int k, vector<int>& nums, vector<int>& result) {
        if (count == 0) return;
        if (idx >= nums.size()) return;

        int take = windowsum[idx] + helper(count - 1, idx + k, k);
        int ntake = helper(count, idx + 1, k);

        if (take >= ntake) {
            result.push_back(idx);
            solve(count - 1, idx + k, k, nums, result);
        } else {
            solve(count, idx + 1, k, nums, result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 3 * k) return {}; // Edge case: not enough elements for three subarrays

        int sum = 0, i = 0, j = 0;

        // Calculate sliding window sums
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) {
                windowsum.push_back(sum);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        int m = windowsum.size();
        dp.resize(m, vector<int>(4, -1)); // Allocate dp for m indices and 4 states (0-3 subarrays)

        vector<int> result;
        solve(3, 0, k, nums, result);
        return result;
    }
};
