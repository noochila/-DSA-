//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        // code here
        if(n<=6) return n;
       vector<long long int>dp(n+1,0);
       for(int i=1;i<=6;i++) {
           dp[i] = i;
       }
       for(int i=7;i<=n;i++) {
           for(int j=i-3;j>=1;j--) {
               int cur = dp[j]*(i-j-1);
               if(cur>dp[i]) {
                   dp[i] = cur;
               }
           }
       }
       return dp[n];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends