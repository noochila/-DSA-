//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  
  
   int solve(int i,int j,string s,bool istrue,  vector<vector<vector<int>>> &dp)
   {
       if(i>j)
       return false;
       
       else if(i==j)
       {
           if(istrue)
           return s[i]=='T';
           else
           return s[i]=='F';
       }
       
       
       if(dp[i][j][istrue]!=-1)
       return dp[i][j][istrue];
       
       int c=0;
       
       for(int k=i+1;k<j;k+=2)
       {
           
           int lt=solve(i,k-1,s,true,dp);
           int lf=solve(i,k-1,s,false,dp);
           int rt=solve(k+1,j,s,true,dp);
           int rf=solve(k+1,j,s,false,dp);
           
           if(s[k]=='|')
           {
               if(istrue)
               c=(c+(lt*rf)+(lf*rt)+(lt*rt));
               else
               c=(c+(lf*rf));
           }
           
           
           if(s[k]=='&')
           {
               if(istrue)
               c=(c+(lt*rt));
               else
               c=(c+(lf*rt)+(lt*rf)+(lf*rf));
           }
           
           if(s[k]=='^')
           {
               if(istrue)
               c=(c+(lt*rf)+(lf*rt));
               else
               c=(c+(lt*rt)+(lf*rf));
           }
           
          
       }
       
         return dp[i][j][istrue]= c;
   }
    int countWays(string &s) {
        // code here
        
        int n=s.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        
        return solve(0,n-1,s,true,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends