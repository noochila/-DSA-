#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();
        vector<long long> dp(n, LLONG_MIN);  // Use long long to avoid overflow
        
        // Initialize dp for the first element of a
        for (int j = 0; j < n; ++j) {
            dp[j] = static_cast<long long>(a[0]) * b[j];  // Cast to long long
        }

        // For the remaining elements of a (a[1], a[2], a[3])
        for (int k = 1; k < 4; ++k) {
            vector<long long> new_dp(n, LLONG_MIN);
            long long max_so_far = LLONG_MIN;
            
            // Traverse the array b for the current k-th element of a
            for (int j = k; j < n; ++j) {
                max_so_far = max(max_so_far, dp[j - 1]);
                new_dp[j] = max_so_far + static_cast<long long>(a[k]) * b[j];  // Cast to long long
            }

            dp = move(new_dp);
        }

        // The maximum score after choosing all 4 elements
        long long result = LLONG_MIN;
        for (int j = 3; j < n; ++j) {
            result = max(result, dp[j]);
        }

        return result;
    }
};
