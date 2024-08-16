//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        //dp i is the maxi no of cuts till index i 
        vector<int> dp(n+1,-1);
        
        // dp[x]++;
        // dp[y]++;
        // dp[z]++;
        dp[0]=0;
        
        
        for(int i=1;i<=n;i++)
        {
            if(i>=x  && dp[i-x]!=-1)
            {
                dp[i]=max(dp[i],1+dp[i-x]);
            }
            
            if(i>=y && dp[i-y]!=-1)
            {
                dp[i]=max(dp[i],1+dp[i-y]);
            }
            
            if(i>=z && dp[i-z]!=-1)
            {
                dp[i]=max(dp[i],1+dp[i-z]);
            }
            // cout<<dp[i]<<endl;
        }
        
    //   int ans=0;
       
    //   for(int i=1;i<=n;i++)
    //   ans=max(ans,dp[i]);
    //   return ans;
        if(dp[n]==-1)
    return 0;
    return dp[n];

    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends