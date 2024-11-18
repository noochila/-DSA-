class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                dp[i]+=dp[i+1];
            }
        }
        int ans = 1;
        int i = 0;
        while(i<n){
            if(i+dp[i]<n){
                int p = min(dp[i],dp[i+dp[i]]);
                ans = max(ans,p);
            }
            int p = max(1,dp[i]/2);
            ans = max(ans,p);
            i++;
        }
        return ans;
    }
};