class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        if (j >= grid[0].size() - 1) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans1 = 0;
        if (i + 1 < grid.size() && j + 1 < grid[0].size() &&
            grid[i + 1][j + 1] > grid[i][j]) {
            ans1 = 1 + solve(i + 1, j + 1, grid, dp);
        }

        int ans2 = 0;
        if (i - 1 >= 0 && j + 1 < grid[0].size() &&
            grid[i - 1][j + 1] > grid[i][j]) {
            ans2 =1+ solve(i - 1, j + 1, grid, dp);
        }

        int ans3 = 0;

        if (j + 1 < grid[0].size() && grid[i][j + 1] > grid[i][j]) {
            ans3 = 1+solve(i, j + 1, grid, dp);
        }
        return dp[i][j] = max({ans1, ans2, ans3});
    }

    int maxMoves(vector<vector<int>>& grid) {
        int maxmoves = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < grid.size(); i++) {
           
          maxmoves=max(maxmoves,solve(i, 0, grid, dp));
        }

        return maxmoves;
    }
};
