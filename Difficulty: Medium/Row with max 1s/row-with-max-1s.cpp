//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
        int max1s = 0;
        int rowIndex = -1;

        for (int i = 0; i < n; i++) {
            int first1 = lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin();
            int num1s = m - first1;  // Number of 1s in the current row

            if (num1s > max1s) {
                max1s = num1s;
                rowIndex = i;
            }
        }

        return rowIndex;
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends