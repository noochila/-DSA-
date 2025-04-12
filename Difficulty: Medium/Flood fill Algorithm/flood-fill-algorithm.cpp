//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
void dfs(int i, int j, vector<vector<int>> &image,
         vector<vector<int>> &visited, int n, int m, int p,vector<vector<int>> &ans) {
  visited[i][j] = 1;
  int t = image[i][j];
  ans[i][j] = p;
  
  int drow[]={-1,0,1,0};
  int dcol[]={0,1,0,-1};
  
  for(int k=0;k<4;k++)
  {
      int rrow=drow[k]+i;
      int rcol=dcol[k]+j;
      
      if(rrow>=0 && rrow<n && rcol>=0 && rcol<m && visited[rrow][rcol]==0 && image[rrow][rcol]==t)
      
      {
           ans[i][j] = p;
  
          dfs(rrow,rcol,image,visited,n,m,p,ans);
      }
  }

  
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int n=image.size();
        int m=image[0].size();
        
         vector<vector<int>> visited(n, vector<int>(m, 0));
         vector<vector<int>> ans(image);

      dfs(sr, sc,  image, visited, n, m, newColor,ans);

  return ans;
        
        
      
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends