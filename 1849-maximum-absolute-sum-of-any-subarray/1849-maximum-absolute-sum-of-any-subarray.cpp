class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        
        int n=nums.size();
        int ans=0;
        int sum=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>0)
            ans=max(ans,sum);
            else
            sum=0;

        }   
        sum=0;

          for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<0)
            ans=max(ans,abs(sum));
            else
            sum=0;

        }     
        return ans;   
    }
};