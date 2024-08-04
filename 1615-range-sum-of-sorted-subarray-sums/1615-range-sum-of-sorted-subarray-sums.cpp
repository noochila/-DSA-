class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1'000'000'007;
        
        // Vector to store all subarray sums
        vector<int> sums;

        // Generate all subarray sums
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }

        // Sort the subarray sums
        sort(sums.begin(), sums.end());

        // Compute the prefix sum array
        vector<long long> prefix(sums.size() + 1, 0);
        for (int i = 1; i <= sums.size(); ++i) {
            prefix[i] = (prefix[i - 1] + sums[i - 1]) % MOD;
        }

        // Return the sum of the range [left, right]
        return (prefix[right] - prefix[left - 1] + MOD) % MOD;
    }
};
