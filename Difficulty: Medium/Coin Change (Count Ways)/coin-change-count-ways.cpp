//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
   
    int solve(int ind,vector<int>&coins,int sum,  vector<vector<int>>& dp)
    {
        if(sum==0)
        return 1;
        if(ind>=coins.size() || sum<0)
        return 0;
        
        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
        
       return  dp[ind][sum]=solve(ind,coins,sum-coins[ind],dp)+solve(ind+1,coins,sum,dp);
        
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        
       vector<vector<int>> dp(coins.size()+1,vector<int>(sum+1,-1));
        return solve(0,coins,sum,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends