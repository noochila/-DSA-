class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefix(2, vector<long long>(n, 0ll));

        prefix[0][0] = grid[0][0];
        prefix[1][0] = grid[1][0];

        for (int i = 1; i < n; i++) {
            prefix[0][i] = prefix[0][i-1] + grid[0][i];
            prefix[1][i] = prefix[1][i-1] + grid[1][i];
            // cout<<prefix[0][i]<<" "<<prefix[1][i]<<endl;
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n; i++) {
            // cout<<prefix[0][n-1]<<" "<<prefix[0][i]<<endl;
            long long cost1 = (i < n) ? prefix[0][n-1]-prefix[0][i]: 0;
            long long cost2 = (i > 0) ? prefix[1][i-1] : 0;
            // cout<<cost1<<" "<<cost2<<endl;
            ans = min(ans, max(cost1, cost2));
        }

        return ans;
    }
};
