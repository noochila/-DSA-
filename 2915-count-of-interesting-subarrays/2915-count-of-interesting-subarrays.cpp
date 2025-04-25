class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        long long ans = 0;
        int n = nums.size();

     

        map<int, int> mp;
        int prefix=0;
        mp[0]=1;
        

        for (int i = 0; i < n; i++) {

            prefix+=nums[i]%modulo==k;
            ans+=mp[(prefix-k+modulo)%modulo];
            mp[prefix%modulo]++;
          
        }
        return ans;

    }
};