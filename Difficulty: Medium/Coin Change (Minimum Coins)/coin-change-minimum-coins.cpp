//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minCoins(vector<int> &coins, int v) {
        // Your code goes here
        int m=coins.size();
        vector<int> dp(v+1,INT_MAX);
        dp[0]= 0;
        for(int i = 0;i<m;i++){
           for(int j = coins[i];j<=v;j++){
               if(dp[j-coins[i]]!=INT_MAX){
                   dp[j] = min(dp[j],dp[j-coins[i]]+1);
               }
           } 
        }
        return dp[v]>=INT_MAX?-1:dp[v];
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends