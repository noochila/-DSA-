class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int maxi = *max_element(nums.begin(), nums.end());

        int i = 0;
        int j = 0;
        int n = nums.size();
        map<int, int> mp;
        long long ans = 0;

        while (j < n) {
            if (nums[j] == maxi)
                mp[nums[j]]++;

            while (i <= j && mp[maxi] >= k) {
                ans += (n - j);
                if(nums[i]==maxi)
                {
                    mp[maxi]--;
                }
                
                i++;
            }
            j++;
        }
        return ans;
    }
};