class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

       int n=grid.size();
       int m=grid[0].size();


       
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
    dp[1][1]=grid[0][0];

     for(int i=2;i<=n;i++)
     {
        dp[i][1]=dp[i-1][1]+grid[i-1][0];
     }

     for(int j=2;j<=m;j++)
     dp[1][j]=dp[1][j-1]+grid[0][j-1];

     for(int i=2;i<=n;i++)
     {
        for(int j=2;j<=m;j++)
        {
            dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
        }
     }

     return dp[n][m];
    
       
        
    }
};