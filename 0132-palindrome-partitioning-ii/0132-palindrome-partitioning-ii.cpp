// class Solution {
// public:
//     bool check(string temp) {
//         int i = 0;
//         int j = temp.size() - 1;
//         while (i < j) {
//             if (temp[i] != temp[j])
//                 return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n + 1, 1e9);
//         dp[0] = -1;

//         for (int i = 1; i <= n; i++) {
//             for (int j = i; j >= 1; j--) {
             
//                 if (check( s.substr(j - 1, i - (j - 1)))) {
//                     dp[i] = min(dp[i], 1 + dp[j - 1]);
//                 }
//             }
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute whether substrings are palindromes
        for (int end = 0; end < n; ++end) {
            for (int start = 0; start <= end; ++start) {
                if (s[start] == s[end] && (end - start <= 2 || isPalindrome[start + 1][end - 1])) {
                    isPalindrome[start][end] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // maximum cuts possible
                for (int j = 0; j < i; ++j) {
                    if (isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};
