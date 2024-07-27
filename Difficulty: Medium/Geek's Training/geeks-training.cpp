//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
       vector<vector<int>> dp(n, vector<int>(3, 0));

    // Initialize the first row of the dp table with the first row of the input array
    for(int i = 0; i < 3; i++) {
        dp[0][i] = arr[0][i];
    }

    // Fill the dp table row by row
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            // Initialize dp[i][j] to 0 before finding the maximum points
            dp[i][j] = 0;
            for(int k = 0; k < 3; k++) {
                // Ensure that the same activity is not chosen consecutively
                if(j != k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + arr[i][j]);
                }
            }
        }
    }

    // Find the maximum points from the last row of the dp table
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends