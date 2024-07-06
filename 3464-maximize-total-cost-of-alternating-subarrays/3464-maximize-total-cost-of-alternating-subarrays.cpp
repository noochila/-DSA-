class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {

        int n=nums.size();

        vector<long long> dp(n+1,-1e9);

        dp[0]=0;


        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]>=0)
            {
                dp[i]=dp[i-1]+nums[i-1];
            }else
            {
                if(i-2>=0)
                dp[i]=nums[i-2]+(-1)*nums[i-1]+dp[i-2];
                
                dp[i]=max(nums[i-1]+dp[i-1],dp[i]);
            }
        }

        for(auto it:dp)
        cout<<it<<" ";

        return dp[n];


        
    }
};