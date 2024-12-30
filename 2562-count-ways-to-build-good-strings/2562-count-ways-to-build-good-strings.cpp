class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int low, int high, int zero, int one, int len,vector<int>&dp) {
       
        if (len > high) return 0;

      
        int count = (len >= low) ? 1 : 0;

        if(dp[len]!=-1)
        return dp[len];
      
        count = (count + solve(low, high, zero, one, len + zero,dp)) % MOD;

        
        count = (count + solve(low, high, zero, one, len + one,dp)) % MOD;

        return dp[len]=count;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(low, high, zero, one, 0,dp);
    }
};
