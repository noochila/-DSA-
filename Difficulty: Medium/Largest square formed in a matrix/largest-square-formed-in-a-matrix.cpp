//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   int solve(int i,int j, vector<vector<int>> &mat,int &maxi,vector<vector<int>> &dp)
   {
       if(i>=mat.size() || j>=mat[0].size())
       return 0;
       
       if(dp[i][j]!=-1)
       return dp[i][j];
       
       
       
       
       int right=solve(i,j+1,mat,maxi,dp);
       int down=solve(i+1,i,mat,maxi,dp);
       int diag=solve(i+1,j+1,mat,maxi,dp);
       
       if(mat[i][j]==1)
       {
           dp[i][j]=1+min(right,min(down,diag));
           maxi=max(maxi,dp[i][j]);
           
           return dp[i][j];
          
       }
       else
       return dp[i][j]= 0;
       
       
   }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        
        // int maxi=0;
        // solve(0,0,mat,maxi,dp);
        
        // return maxi;
        
        int maxi=0;
        
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),curr(m+1,0);
        
        
        for(int i=n-1;i>=0;i--)
        {
          for(int j=m-1;j>=0;j--)
          {
              
              
               
       int right=curr[j+1];
       int down=prev[j];
       int diag=prev[j+1];
       
       if(mat[i][j]==1)
       {
          curr[j]=1+min(right,min(down,diag));
           maxi=max(maxi,curr[j]);
          
       }
       else
        curr[j]= 0;
              
          }
          
          prev=curr;
        }
        
        
        return maxi;
        
        
        
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends