//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    
    bool searchMatrix(vector<vector<int>> &mat, int t) {
        // code here
        
        int n=mat.size();
        int m=mat[0].size();
        
        int low=0;
        int high=n*m-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            int x=mid/m;
            int y=mid%m;
            
            if(mat[x][y]==t)
            return true;
            else if(mat[x][y]<t)
            low=mid+1;
            else
            high=mid-1;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends