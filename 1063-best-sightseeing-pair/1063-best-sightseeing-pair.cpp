class Solution {
public:
    int solve(vector<int>& values, int count, int idx,
              vector<vector<int>>& dp) {
        if (count == 0)
            return 0;
        if (idx >= values.size())
            return -1e9;

        if (dp[idx][count] != -1)
            return dp[idx][count];

        if (count == 2) {
            return dp[idx][count] =
                       max(values[idx] + idx +
                               solve(values, count - 1, idx + 1, dp),
                           solve(values, count, idx + 1, dp));
        } else {
            return dp[idx][count] =
                       max(values[idx] - idx +
                               solve(values, count - 1, idx + 1, dp),
                           solve(values, count, idx + 1, dp));
        }
    }

    int maxScoreSightseeingPair(vector<int>& values) {

        // vector<vector<int>>dp(values.size()+1,vector<int>(3,-1));
        vector<vector<int>> dp(values.size() + 1, vector<int>(3, -1e9));

        // return solve(values, 2, 0,dp);

        for(int i=0;i<=values.size();i++)
        {
            dp[i][0]=0;
        }

    

        for (int idx = values.size() - 1; idx >= 0; idx--) {
            for (int count = 2; count >= 1; count--) {

                if (count == 2) {
                    dp[idx][count] =
                        max(values[idx] + idx + dp[idx + 1][count - 1],
                            dp[idx + 1][count]);
                } else {
                    dp[idx][count] =
                        max(values[idx] - idx + dp[idx + 1][count - 1],
                            dp[idx + 1][count]);
                }
            }
        }
        return dp[0][2];
    }
};