class Solution {
public:
    
   int mod=7+1e9;
    int solve(int ind,int gcd1,int gcd2,vector<int>&nums, vector<vector<vector<long long>>>& dp)
    {
          if(ind>=nums.size())
          {
             return gcd1==gcd2 && gcd1!=0;
          }

          if(dp[ind][gcd1][gcd2]!=-1)
          return dp[ind][gcd1][gcd2];

        long long ans1=solve(ind+1,gcd(gcd1,nums[ind]),gcd2,nums,dp);
        long long ans2=solve(ind+1,gcd1,gcd(gcd2,nums[ind]),nums,dp);
        long long ans3=solve(ind+1,gcd1,gcd2,nums,dp);

        return dp[ind][gcd1][gcd2]=(ans1+ans2+ans3)%mod;
    }


    int subsequencePairCount(vector<int>& nums) {


             int n=nums.size();
             int maxGCD=200;

             vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(maxGCD + 1, vector<long long>(maxGCD + 1, -1)));



              return solve(0,0,0,nums,dp);





        
    }
};