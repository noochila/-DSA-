//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    
    int isSubsetSum(int arr[], int sum,int  n){
        // code here 
    
        

        int dp[n+1][sum+1];
        
    
        for(int j=0;j<=n;j++)
        dp[j][0]=1;
        
        for(int i=1;i<=sum;i++)
        dp[0][i]=0;
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                if(arr[i-1]<=j)
                dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        
        
        int mini=1e9;
      for(int i=0;i<=sum/2;i++)
      {
          if(dp[n][i])
          {
              mini=min(mini,abs(sum-2*i));
          }
      }
      
      return mini;
    
        
    }
  
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	  
	      
	      
	      int range=accumulate(arr,arr+n,0);
	      
	      
	     return isSubsetSum(arr,range,n);
	      
	   
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends