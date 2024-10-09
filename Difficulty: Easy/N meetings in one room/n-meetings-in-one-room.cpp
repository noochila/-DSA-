//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
    int maxMeetings(int n, int start[], int end[]) {
        
        std::vector<std::pair<int, int>> a;
    
    for(int i = 0; i < n; i++) {
        a.push_back({start[i], end[i]});
    }
    
    std::sort(a.begin(), a.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });
    
    int val = 1;
    int prev = a[0].second;
    
    for(int i = 1; i < n; i++) {
        if (prev < a[i].first) {
            prev = a[i].second;
            val++;
        }
    }
    
    return val;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends