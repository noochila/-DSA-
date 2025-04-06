class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();
        vector<int> track(n,-1);
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j])
                {
                    
                    dp[i]=1+dp[j];
                    track[i]=j;
                }
            }
        }

        vector<int>ans;

        int  ind=max_element(dp.begin(),dp.end())-dp.begin();
    
        for(int i=ind;i!=-1;i=track[i])
        {

            ans.push_back(nums[i]);

        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};