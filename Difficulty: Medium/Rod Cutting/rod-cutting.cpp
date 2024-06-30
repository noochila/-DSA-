//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        
    //    dp[i] is the best cost to cut the rod of length i 
    
    vector<int> dp(n+1,0);
    dp[1]=price[0];
    
    
    for(int i=2;i<=n;i++)
    {
        for(int len=1;len<=i;len++)
        dp[i]=max(dp[i],dp[i-len]+price[len-1]);
        
        // cout<<dp[i]<<endl;
    }
    
    
    return dp[n];
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends