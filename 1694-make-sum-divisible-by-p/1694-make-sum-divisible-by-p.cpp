class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int mini = 1e9;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0ll);

       

        int target = (total_sum % p);
        int n = nums.size();

        if(target==0)
        return 0;

        map<long long, int> mp;

        mp[0] = -1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum = (sum+nums[i])%p;

            int req = (sum - target+p)%p;

            if (mp.find(req) != mp.end()) {
                mini = min(mini, i - mp[req]);
            }

                mp[sum]=i;
        }

        if (mini == 1e9 || mini==n)
            return -1;
        return mini;
    }
};