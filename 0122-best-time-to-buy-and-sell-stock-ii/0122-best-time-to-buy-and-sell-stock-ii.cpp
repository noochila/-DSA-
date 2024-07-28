class Solution {
public:
   int solve(vector<int>& prices ,int buy,int ind ,  vector<vector<int>>&dp)
   {
    if(ind>=prices.size())
    return 0;
    int profit=0;

    if(dp[ind][buy]!=-1)
    return dp[ind][buy];

     if(buy)
     {
         profit=max(-prices[ind]+solve(prices,0,ind+1,dp),solve(prices,1,ind+1,dp));
     }else
     profit=max(prices[ind]+solve(prices,1,ind+1,dp),solve(prices,0,ind+1,dp));

     return dp[ind][buy]=profit;
   }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<int>>dp(n+1,vector<int>(2,-1));
         return solve(prices,1,0,dp);  
     
    }
};