class Solution {
public:
    int solve(vector<int>& values, int count, int idx,      vector<vector<int>>&dp) {
        if ( count == 0)
            return 0;
        if(idx>=values.size())
        return -1e9;

        if(dp[idx][count]!=-1)
        return dp[idx][count];

        if (count == 2) {
            return dp[idx][count]= max(values[idx] + idx + solve(values,count - 1, idx + 1,dp),
                       solve(values,count, idx + 1,dp));
        } else {
            return dp[idx][count]=max(values[idx] - idx + solve(values,count - 1, idx + 1,dp),
                       solve(values,count, idx + 1,dp));
        }
    }

    int maxScoreSightseeingPair(vector<int>& values) {

        vector<vector<int>>dp(values.size()+1,vector<int>(3,-1));

        return solve(values, 2, 0,dp);
    }
};