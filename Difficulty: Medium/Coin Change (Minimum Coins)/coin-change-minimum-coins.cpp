//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        
        sort(coins.begin(),coins.end());
        
        vector<int> dp(sum+3,1e9); //mini no of coins to make sum 0;
        dp[0]=0;  // 0 coins to make sum 0
        // 
        
     
        
        for(int i=1;i<=sum;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0)
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
                
            }
            // cout<<i<< " "<<dp[i]<<endl;
        }
        
        if(dp[sum]==1e9)
        return -1;
        else
        return dp[sum];
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends