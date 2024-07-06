class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {


        int n=nums.size();


        unordered_map<int,int>mp;

        for(auto it:nums)
        mp[it]++;

        for(int i=1;i<=1e6;i++)
        {
            if(mp[i]==0)
            return i;
        }

        return 0;
        
    }
};