//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        
        
    //     sum1-x1+x2=sum2-x2+x1;
    //     sum1-sum2=2(x1-x2);
    //     sum1-sum2/2=x1-x2;
        
    //   x2+k=x1; 
    
    int sum1=accumulate(a,a+n,0);
    int sum2=accumulate(b,b+m,0);
    
    
    int diff=sum1-sum2;
    if(diff%2)
    return -1;
    diff=diff/2;
    
    sort(b,b+m);
    sort(a,a+n);
    
    
    
    for(int i=0;i<n;i++)
    {
        int req=a[i]-diff;
        
        // cout<<diff<<" "<<req<<endl;
        
        
        
        if(*lower_bound(b,b+m,req)==req)
        return  1;
        
    }
    
    return -1;
    
    
    
    
      
      
      
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends