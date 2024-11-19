class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;
        long long sum = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        map<int, int> mp;

        while (j < n) {
            mp[nums[j]]++;
            sum += nums[j];
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    ans = max(ans, sum);
                }

                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);

                
                i++;
                
            }
            j++;
        }

        return ans;
    }
};