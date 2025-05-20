class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        int n=nums.size();

        vector<int> diff(n+1,0);

        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            diff[x]+=1;
            diff[y+1]-=1;


        }

        for(int i=1;i<n;i++)
        diff[i]+=diff[i-1];

        for(int i=0;i<n;i++)
        {
            if(diff[i]<nums[i])
            return false;

        }

        return true;
        
    }
};