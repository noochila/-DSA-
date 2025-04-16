class Solution {
public:
    long long countGood(vector<int>& nums, int k) {


        int n=nums.size();
        long long pair_count=0;
        long long ans=0;

        map<int,int>mp;
        int i=0;
        int j=0;

        while(j<n)
        {
            mp[nums[j]]++;
            pair_count+=mp[nums[j]]-1;
            while(i<j && pair_count>=k)
            {
                ans+=n-j;
                mp[nums[i]]--;
                pair_count-=mp[nums[i]];
                i++;
            }
            j++;
        }

        return ans;
        
    }
};