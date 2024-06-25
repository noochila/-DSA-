//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void rotatearr(vector<int>&arr,int n, int d){
        if(d==0||d==n)return;
        
        d=d%n;
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.begin()+n);
        reverse(arr.begin(),arr.begin()+n);
    }
    
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> &mat) {
        int n=mat[0].size();
        
        for(auto &itr:mat){
            rotatearr(itr,n,k);
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(k, mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}

// } Driver Code Ends