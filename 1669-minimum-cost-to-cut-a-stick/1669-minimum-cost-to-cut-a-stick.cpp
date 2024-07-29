class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        // Base case: If no cuts needed between i and j
        if (i + 1 == j) return 0;
        
        // If result is already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int cost = cuts[j] - cuts[i] + solve(i, k, cuts, dp) + solve(k, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        // Add the two ends of the stick to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return solve(0, m - 1, cuts, dp);
    }
};
