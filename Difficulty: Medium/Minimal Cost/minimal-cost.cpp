//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        vector<int> dp(arr.size()+1,1e9);
        dp[0]=0;
        
        for(int i=0;i<arr.size();i++)
        {
           for(int j=1;j<=k;j++)
           {
               if(i-j>=0)
               dp[i]=min(dp[i],abs(arr[i]-arr[i-j])+dp[i-j]);
           }
        //   cout<<dp[i]<<" ";
        }
        
        return dp[arr.size()-1];
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
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends