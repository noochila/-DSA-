class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {

        int i=0;
        int j=0;

        int maxcount=0;
        map<int,int>mp;

        int n=nums.size();
        
        int len=0;


        while(j<n)
        {
            mp[nums[j]]++;

            maxcount=max(maxcount,mp[nums[j]]);

            while((j-i+1)-maxcount>k)
            mp[nums[i++]]--;

            len=max(len,maxcount);
            j++;

        }

        return len;
        
    }
};