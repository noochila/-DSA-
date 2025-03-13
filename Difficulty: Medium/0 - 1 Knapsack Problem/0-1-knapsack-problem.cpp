//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
          int n=wt.size();
         vector<vector<int>>dp(n+1,vector<int>(W+1,0));
       
       for(int i=0;i<=n;i++)
       dp[i][0]=0;
       
       for(int j=0;j<=W;j++)
       dp[0][j]=0;
       
       for(int i=1;i<=n;i++)
       {
           for(int j=0;j<=W;j++)
           {
               int ntake=dp[i-1][j];
               int take=0;
               if(j-wt[i-1]>=0)
                take=val[i-1]+dp[i-1][j-wt[i-1]];
              
              dp[i][j]=max(ntake,take);
               
           }
       }
       
       return dp[n][W];
        
        
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends