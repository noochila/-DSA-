//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	long long int solve(long long x,long long n,long long m)
	{
	     if(n==0)
	     return 1;
	     else{
	     long long ans=solve(x,n/2,m)%m;
	     ans=(ans*ans)%m;
	     if(n%2)
	     ans=(ans*x);
	      return ans%m;
	    }
	}
	
		long long int PowMod(long long int x,long long int n,long long int M)
		{

		   return solve(x,n,M)%M;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends