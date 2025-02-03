class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        
        int increasemax=1;
        int increasemin=1;
        
        int n=nums.size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n-1;j++)
            {   
                if(nums[j]<nums[j+1])
                    increasemax=max(increasemax,j+1-i+1);
                else
                    break;
            
            }
        }
        
         for(int i=0;i<n;i++)
        {
            for(int j=i;j<n-1;j++)
            {   
                if(nums[j]>nums[j+1])
                    increasemin=max(increasemin,j+1-i+1);
                else
                    break;
            
            }
        }
        
        return max(increasemax,increasemin);
        
    }
};