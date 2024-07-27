//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    
    int solve(int i,int j ,int k,vector<vector<int>>&grid,  vector<vector<vector<int>>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        // Base case: if we have reached beyond the last row
        if (i == n) return 0;
        
        // If already computed, return the cached result
        if (dp[i][j][k] != -1) return dp[i][j][k];
        
        int ans = 0;
        
        for (int l1 = -1; l1 <= 1; l1++) {
            for (int l2 = -1; l2 <= 1; l2++) {
                int nj = j + l1;
                int nk = k + l2;
                if (nj >= 0 && nj < m && nk >= 0 && nk < m) {
                    int value = (j == k) ? grid[i][j] : grid[i][j] + grid[i][k];
                    ans = max(ans, value + solve(i + 1, nj, nk, grid, dp));
                }
            }
        }
        
        // Cache and return the result
        return dp[i][j][k] = ans;
      
        
    }
  
  
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        // Start the recursion from the top row and both paths at the extreme ends of the first row
        return solve(0, 0, m - 1, grid, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends