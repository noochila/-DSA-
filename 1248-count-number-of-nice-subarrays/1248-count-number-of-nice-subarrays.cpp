class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2)
                nums[i] = 1;
            else
                nums[i] = 0;
        }

        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int prefix = sum - k;

            ans += mp[prefix];
            mp[sum]++;
        }
        return ans;
      
    }
};