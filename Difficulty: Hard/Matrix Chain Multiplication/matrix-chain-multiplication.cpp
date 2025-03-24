//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int solve(int arr[], int n, int i, int j, vector<vector<int>> &dp)
                            {
                                if (i >= j)
                                    return 0;
                            
                                int ans = 1e9;
                            
                                if (dp[i][j] != -1)
                                    return dp[i][j];
                            
                                for (int k = i; k < j; k++)
                                {
                                    ans = min(solve(arr, n, i, k, dp) + solve(arr, n, k + 1, j, dp) + arr[i - 1] * arr[j] * arr[k], ans);
                                }
                                return dp[i][j] = ans;
                            }
    int matrixMultiplication(vector<int> &arr) {
        int N=arr.size();
        // code here
          vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

for (int i = N - 1; i >= 1; i--) {
    for (int j = i + 1; j <= N - 1; j++) {
        int ans = 1e9;
        for (int k = i; k < j; k++) {
            ans = min(ans, dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
        }
        dp[i][j] = ans;
    }
}

return dp[1][N-1];

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends