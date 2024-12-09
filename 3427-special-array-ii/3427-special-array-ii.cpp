class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();
        vector<int> a(n,0);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]%2!=nums[i]%2)
            a[i]++;
        }

        for(int i=1;i<n;i++)
        a[i]+=a[i-1];

        vector<bool> ans;

        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];

            if(a[y]-a[x]==(y-x))
            ans.push_back(true);
            else
            ans.push_back(false);

        }
        return ans;
        
    }
};