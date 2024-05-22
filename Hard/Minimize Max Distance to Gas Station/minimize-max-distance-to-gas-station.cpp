//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
 double findSmallestMaxDist(vector<int> &stations, int k) {
        auto isValid = [](double maxDist, const vector<int>& positions, int maxStations) {
            int reqStations = 0;
            for (int i = 1; i < positions.size(); ++i) {
                double dst = positions[i] - positions[i - 1];
                reqStations += static_cast<int>(dst / maxDist);
            }
            return reqStations <= maxStations;
        };
        
        // binary search in answer's range
        double l = 0;
        double r = stations.back() - stations.front();
        double res = r;
        
        // difference r-l should be greater then epsilon
        while (r - l > 1e-6) {
            double m = (l + r) / 2.0;
            if (isValid(m, stations, k)) {
                r = m;
                res = m;
            } else {
                l = m;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends