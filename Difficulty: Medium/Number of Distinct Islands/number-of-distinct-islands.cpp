//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>>&vis,
  vector<pair<int,int>>&vec, int srow, int scol){
      vis[row][col] =  1;
      vec.push_back({row-srow,col-scol});
      
        int n = grid.size();
        int m = grid[0].size();
      
      vector<pair<int,int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};
      
      for(int i = 0; i < 4; i++){
          int nrow = row+dir[i].first;
          int ncol = col+dir[i].second;
          if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]
          && grid[nrow][ncol] == 1){
              dfs(nrow,ncol,grid,vis,vec,srow,scol);
          }
      }
  }
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>> st;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vector<pair<int,int>> vec;
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends