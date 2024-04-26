//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        // 0,1 -> 1,1 
        //1,1 ->  1,0
        // 0 right
        // 1  down
        //2 left
        // 3 up
        
        
    int prev = 0;
    vector<pair<int, int>> move = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<pair<int, int>> movesame = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int i = 0;
    int j = 0;
    
    int rx=0;
    int ry=0;

    while (j < m && i < n ) {
        if (matrix[i][j] == 0) {
            
            rx=i;
            ry=j;
            
            i = movesame[prev].first + i;
            j = movesame[prev].second + j;
           
            
            if(i<0 || j>=m || i>=n || j<0)
            return {rx,ry};
            
            
            
            
         
        } else {
            matrix[i][j] = 0;
            int x = i;
            int y = j;
            i = move[prev].first + x;
            j = move[prev].second + y;
            // cout<<i<<" "<<j<<endl;
            prev = (prev + 1) % 4;
            rx=x;
            ry=y;
            
              if(i<0 || j>=m || i>=n || j<0)
            return {rx,ry};
            
            
          
        }
    }
    return {-1, -1}; // Not found
        
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
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends