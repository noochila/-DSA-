//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    
    int solve(vector<int>&prices,int buy,int ind,vector<vector<int>>&dp)
    {
        if(ind>=prices.size())
        return 0;
        
        if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
        if(buy)
        {
            return dp[ind][buy]=max(-prices[ind]+solve(prices,0,ind+1,dp),solve(prices,buy,ind+1,dp));
        }else
        {
            return dp[ind][buy]=max(prices[ind]+solve(prices,1,ind+1,dp),solve(prices,buy,ind+1,dp));
        }
    }
  
  
    int maximumProfit(vector<int> &prices) {
        // code here
        
        int n=prices.size();
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        
        return solve(prices,1,0,dp);
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends