//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        
      int removals=0;
      int last=INT_MIN;
      for(auto it:intervals)
      {
          if(it[0]<last)
          removals++;
          else
          {
              last=it[1];
          }
      }
      return removals;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends