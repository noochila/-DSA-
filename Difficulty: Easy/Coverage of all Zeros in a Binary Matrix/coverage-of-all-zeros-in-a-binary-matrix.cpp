//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        
        
        int ans=0;
        
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        
                        if(nx<0 ||nx>=matrix.size() || ny<0  || ny>=matrix[i].size())
                        {
                            
                        }else
                        {
                            if(matrix[nx][ny]==1)
                            ans++;
                        }
                    }
                
                }
            }
        }
        
        
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends