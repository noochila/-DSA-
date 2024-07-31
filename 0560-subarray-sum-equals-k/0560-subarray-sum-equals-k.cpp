class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(auto it:nums)
        {
            sum+=it;
            int req=sum-k;
            count+=mp[req];
            mp[sum]++;

        }

        return count;
        
    }
};