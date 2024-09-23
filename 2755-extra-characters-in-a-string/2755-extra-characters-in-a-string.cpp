class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        unordered_map<string, int> mp;
        for (auto it : dic) {
            mp[it]++;
        }

        int n = s.size();
        vector<int> dp(n + 1, INT_MAX); // dp[i] represents the minimum number of extra chars up to i
        dp[0] = 0; // No extra characters needed at the start

        for (int i = 0; i < n; ++i) {
            // If the dp[i] is INT_MAX, skip it
            if (dp[i] == INT_MAX) continue;

            // Try every possible substring starting from index i
            for (int j = i + 1; j <= n; ++j) {
                string temp = s.substr(i, j - i); // Get substring from i to j-1
                if (mp.find(temp) != mp.end()) {
                    // If it's in the dictionary, no extra characters for this part
                    dp[j] = min(dp[j], dp[i]);
                } else {
                    // If not in dictionary, count all characters as extra
                    dp[j] = min(dp[j], dp[i] + (j - i));
                }
            }
        }

        return dp[n]; // Minimum number of extra characters for the entire string
    }
};
