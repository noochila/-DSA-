class Solution {
public:

   long long solve(int ind,vector<vector<int>>&q,vector<long long>&dp)
   {
        if(ind>=q.size())
        return 0;

        if(dp[ind]!=-1)
        return dp[ind];

        return dp[ind]= max(q[ind][0]+solve(ind+q[ind][1]+1,q,dp),solve(ind+1,q,dp));
   }
    long long mostPoints(vector<vector<int>>& questions) {
    
       int n=questions.size();
        vector<long long> dp(n+1,-1);

        return solve(0,questions,dp);
        
    }
};