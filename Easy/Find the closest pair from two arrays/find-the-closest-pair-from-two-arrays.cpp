//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {

       int l{}, r{ m-1 }, a{}, b{}, xmin{ INT_MAX };
    while ( l < n && r >= 0 ) {
        const int s{ arr[ l ] + brr[ r ] }, xcur{ abs( x - s ) };
        if ( xcur < xmin ) xmin = xcur, a = l, b = r;
        s < x ? ++l : --r;
    }
    return { arr[ a ], brr[ b ] };
        
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends