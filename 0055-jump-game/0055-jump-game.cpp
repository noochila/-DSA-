class Solution {
public:

   bool solve(vector<int>&nums,int ind,vector<int>&dp)
   {
    
      if(ind>=nums.size()-1)
      {
        return true;
      }

      if(dp[ind]!=-1)
      return dp[ind];

      

        for(int k=1;k<=nums[ind];k++)
        {
             if(solve(nums,k+ind,dp))
             return dp[ind]=true;
        }


    
        return  dp[ind]=false;
      

   }

    bool canJump(vector<int>& nums) {

        int n=nums.size();
    
     vector<int> dp(n,-1);
         return solve(nums,0,dp);
        
    }
};