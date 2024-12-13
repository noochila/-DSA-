class Solution {
public:
    long long findScore(vector<int>& nums) {


        multiset<pair<int,int>> s;

        for(int i=0;i<nums.size();i++)
        {
            s.insert({nums[i],i});
        }

        //set
        //in o(1) we need to find the adj ele 
        //but we can't use map since 

        long long ans=0;
        while(!s.empty())
        {
            int mini=s.begin()->first;
            int idx=s.begin()->second;

            if(idx-1>=0)
            s.erase({nums[idx-1],idx-1});
            if(idx+1<nums.size())
            s.erase({nums[idx+1],idx+1});
            ans+=mini;
            s.erase({mini,idx});

        }

        return ans;
        
    }
};