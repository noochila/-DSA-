//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int k)
	{
        // Your code goes here
        
      int mod=1e9+7;



    vector<vector<int>>dp(n+1,vector<int>(k+1,0));

   dp[0][0]=1;
    

    


    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
              int ntake=dp[i-1][j];

              int take=0;

              if(j-arr[i-1]>=0)
              take=dp[i-1][j-arr[i-1]];

              dp[i][j]=(take%mod + ntake%mod)%mod;

        }
    }
    return dp[n][k];

	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends