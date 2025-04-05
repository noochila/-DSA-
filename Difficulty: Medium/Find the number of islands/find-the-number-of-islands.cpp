//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int i,int j,vector<vector<char>>& roads,vector<vector<int>>&visited,int n,int m)
{
    
     visited[i][j]=1;
     
    
     
       for(int drow=-1;drow<=1;drow++)
       {
           for(int dcol=-1;dcol<=1;dcol++)
           {
               int nrow=drow+i;
               int ncol=dcol+j;
               
               if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && roads[nrow][ncol]=='L' && visited[nrow][ncol]==0)
               dfs(nrow,ncol,roads,visited,n,m);
           }
       }
     

    
}



int findNumOfProvinces(vector<vector<char>>& roads, int n,int m) {
    // Write your code here.

    int count=0;

    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0 && roads[i][j]=='L')
            {
        
                dfs(i,j,roads,visited,n,m);
                count++;
            }

        }
    }

    return count;
    
}
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        return findNumOfProvinces(grid,grid.size(),grid[0].size());
        
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends