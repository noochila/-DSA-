class Solution {
public:
    int convert(int s, int e, string st) {
        int ans = 0;
        int i = 0;
        while (e >= s) {
            if (st[e] == '1')
                ans += pow(2, i);

            i++;
            e--;
        }
        return ans;
    }

    int minimumBeautifulSubstrings(string s) {

        int n = s.size();
        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int ans = 1e9;
            for (int prt = i; prt >= 0; prt--) {

                int val = convert(prt, i, s);

                if (val != 0 && 15625 % val == 0 && s[prt] != '0' )
                    ans = min(ans, dp[prt] + 1);
            }

            dp[i+1]=ans;
        }
         if (dp[n]==1e9)
         return -1;
        return dp[n];
    
    }
};