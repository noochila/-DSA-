class Solution {
public:


     bool check(vector<int>& nums, int k) {
         vector<int>prefix(nums.size());
        
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + (nums[i] > nums[i - 1] ? 1 : 0);
        }
        
        for(int i = 0; i + 2 * k - 1 < nums.size(); i++) {
            if((prefix[i + k - 1] - prefix[i] == k - 1) && (prefix[i + 2*k - 1] - prefix[i + k] == k - 1)) {
                return true;
            }
        }
        
        return false;
        
        
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,1);
        // for(int i=n-2;i>=0;i--){
        //     if(nums[i] < nums[i+1]){
        //         dp[i]+=dp[i+1];
        //     }
        // }
        // int ans = 1;
        // int i = 0;
        // while(i<n){
        //     if(i+dp[i]<n){
        //         int p = min(dp[i],dp[i+dp[i]]);
        //         ans = max(ans,p);
        //     }
        //     int p = max(1,dp[i]/2);
        //     ans = max(ans,p);
        //     i++;
        // }
        // return ans;
        int low=1;
        int high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(check(nums,mid))
            {
                low=mid+1;
            }else
            {
                high=mid-1;
            }
        }

        return high;
    }
};