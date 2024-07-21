//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
          int n=arr.size();
        
        if(n==1)return arr[0];
        
        long long int maxi=-11;
        long long int prod=0;
        long long int cnt=0;
        
        
        
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                if(prod==0){
                    prod=1;
                }
                prod=(prod*(long long)arr[i])%mod;
                if(arr[i]<0){
                    cnt++;
                    maxi=max(maxi,(long long int)arr[i]);
                }
            }
        }
        
        if(cnt==1&&prod==-1&&n>cnt)return 0;
        
        
        if(cnt%2==0)return prod%mod;
        
        prod/=maxi;
        
        return prod%mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends