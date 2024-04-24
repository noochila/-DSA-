//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    int A[501][501] = {}, mod = 1e9+7;
public:
    int ways(int x, int y){
       if(x==0 && y==0) return 1;
       if(x<0 || y<0) return 0;
       if(A[x][y]) return A[x][y];
       return A[x][y] = (ways(x-1, y) + ways(x, y-1))%mod;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends