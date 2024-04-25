//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
         int ans = -1;
   
    if (n == 0) return ans; // Handle empty matrix case
    
    if (m == 0) return ans; // Handle matrix with empty rows
    
    // Ensure that the loop conditions are safe
    for (int i = 0; i <= n - 3; i++) { // Adjusted loop condition for i
        for (int j = 0; j <= m - 3; j++) { // Adjusted loop condition for j
            // Calculate sum of the submatrix starting at (i, j)
            int firstrow = accumulate(mat[i].begin() + j, mat[i].begin() + j + 3, 0);
            int secondrow = mat[i + 1][j + 1];
            int thirdrow = accumulate(mat[i + 2].begin() + j, mat[i + 2].begin() + j + 3, 0);
            
            // Update maximum sum found
            ans = max(ans, firstrow + secondrow + thirdrow);
        }
    }
    
    return ans;
        
        
        
        // code here
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends