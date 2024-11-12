//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    struct compare{
      
      bool operator()(auto a,auto b)
      {
          return (a[1]<b[1]);
          
      }
    };
  
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        
        
        sort(arr.begin(),arr.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        
        int end=arr[0][1];
        
        
        int i=1;
        int n=arr.size();
        int c=1;
        
        while(i<n)
        {
            if(arr[i][0]>=end)
            {
                end=arr[i][1];
                c++;
            }
            i++;
        }
        
        
        if(c==n)
        return true;
        else
        return false;
        
        

        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends