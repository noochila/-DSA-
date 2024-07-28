class Solution {
public:
 int longestCommonSubsequence(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();
        // return solve(text1,text2,n,m);

       vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] =  dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = 1+ min(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
    }
    int minDistance(string word1, string word2) {
         return longestCommonSubsequence(word1,word2);
    }
};