//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numberOfWays(int n) {
        //code here
        
        int mod=7+1e9;
        
        
        vector<long long> dp(n+1);
        
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        dp[i]=(dp[i-2]+dp[i-1])%mod;
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.numberOfWays(n) << endl;
    }
    return 0;
}
// } Driver Code Ends