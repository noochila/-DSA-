//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        /*
        0900 1100 1235
        1000 1200 1240
        */
        
        sort(arr.begin(),arr.end());
        
        sort(dep.begin(),dep.end());
        
        int i=1;
        int j=0;
        int n=arr.size();
        int m=dep.size();
        int count=1;
        int ans=1;
        
        while(i<n && j<m)
        {
            if(arr[i]<=dep[j])
            {
                count++;
                i++;
            }else
            {
                ans=max(ans,count);
                count--;
                j++;
                
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;
    }
    return 0;
}
// } Driver Code Ends