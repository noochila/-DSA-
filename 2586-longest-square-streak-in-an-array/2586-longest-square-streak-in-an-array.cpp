class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_map<long long,int>mp;

        for(auto it:nums)
        mp[it]++;

        int ans=0;

        for(auto it:nums)
        {
            int c=1;
            long long ele=it;
            while(mp.find(ele*ele)!=mp.end())
            {
                c++;
                ele=ele*ele;
            }

            ans=max(ans,c);

        }

        if(ans>1)return ans;
        return -1;
    }
};