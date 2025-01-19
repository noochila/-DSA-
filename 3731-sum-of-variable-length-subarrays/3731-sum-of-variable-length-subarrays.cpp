class Solution {
public:
    int subarraySum(vector<int>& nums) {



        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int start=max(0,i-nums[i]);
            int sum=0;
            for(int j=start;j<=i;j++)
            {
                sum+=nums[j];

            }
            ans+=sum;
        }



        return ans;
        
    }
};