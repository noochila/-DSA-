class Solution {
public:
    unordered_map<int, int> mp;

    void solve(int ind, vector<int>& nums,vector<int>temp)

    {
        if (ind >= nums.size()) {
            int val = accumulate(temp.begin(), temp.end(), 0,
                                 [&](int a, int b) { return a | b; });
            mp[val]++;
            return;
        }

        temp.push_back(nums[ind]);
        solve(ind+1,nums,temp);
        temp.pop_back();
        solve(ind+1,nums,temp);

        return ;
    }

    int countMaxOrSubsets(vector<int>& nums) {

        vector<int> temp;
        solve(0, nums, temp);

        int ans=0;
        int val=0;

        for(auto it:mp)
        {
            // cout<<it.first<<" "<<it.second<<endl; 
            if(it.first>val)
            {
                val=it.first;
                ans=it.second;
            }
        }

        return ans;
    }
};