//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int mod=1003;
  
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
               c=(c+(lt*rf)%mod+(lf*rt)%mod+(lt*rt)%mod)%mod;
               else
               c=(c+(lf*rf)%mod)%mod;
           }
           
           
           if(s[k]=='&')
           {
               if(istrue)
               c=(c+(lt*rt)%mod)%mod;
               else
               c=(c+(lf*rt)%mod+(lt*rf)%mod+(lf*rf)%mod)%mod;
           }
           
           if(s[k]=='^')
           {
               if(istrue)
               c=(c+(lt*rf)%mod+(lf*rt)%mod)%mod;
               else
               c=(c+(lt*rt)%mod+(lf*rf)%mod)%mod;
           }
           
          
       }
       
         return dp[i][j][istrue]= c%mod;
   }

  
    int countWays(int n, string s){
        // code here
         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

        
        return solve(0,n-1,s,true,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends