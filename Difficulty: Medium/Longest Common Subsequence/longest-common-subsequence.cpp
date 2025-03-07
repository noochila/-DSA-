//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
   auto  solve=[&](int i,int j,auto &self)->int{
          if(i>=s1.size() || (j>=s2.size()))
          return 0;
          if(dp[i][j]!=-1)
          return dp[i][j];
          
          if(s1[i]==s2[j])
          return dp[i][j]=1+self(i+1,j+1,self);
          else
          return dp[i][j]=max(self(i+1,j,self),self(i,j+1,self));
      };
      
      return solve(0,0,solve);
      
      
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends