class Solution {
public:
    int check(string s1, string s2) {
        if (s1.size() != s2.size())
        return -1;

        int len = s1.size();
        int c = 0;

        for (int i = 0; i < len; i++) {
            if (s1[i] != s2[i])
                c++;
        }
        return c;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {

        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> path(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (groups[i] != groups[j] && 1 + dp[j] > dp[i] &&
                    check(words[i], words[j]) == 1) {

                    path[i] = j;
                    dp[i] = 1 + dp[j];
                }
            }
        }

        auto maxi = max_element(begin(dp), end(dp)) - begin(dp);
        vector<string> ans;

        for (int i = maxi; i != -1; i = path[i]) {
            ans.push_back(words[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};