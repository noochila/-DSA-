class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = n - 1; i > 1; i--) {
            long long sum = accumulate(nums.begin(), nums.end() - (n-i), 0LL);  // Use long long for the sum

            // cout << sum << endl;

            if (sum > nums[i]) {
                return sum + nums[i];
            }
        }

        return -1;
    }
};
