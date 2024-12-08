class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        int n=a.size();

        vector<vector<int>> dp(n+1,vector<int>(2,-1));


        auto solve = [&](int idx, int count, auto&& self) -> int {
            if (count == 2 || idx >= a.size()) {
                return 0;
            }

            if(dp[idx][count]!=-1)
            return dp[idx][count];

           
            int nextidx = upper_bound(a.begin(), a.end(), a[idx][1], [](int val, const vector<int>& event) {
                return val < event[0];
            }) - a.begin();

            int take = a[idx][2] + self(nextidx, count + 1, self);
            int ntake = self(idx + 1, count, self);

            return dp[idx][count]=max(take, ntake);
        };

        return solve(0, 0, solve);
    }
};
