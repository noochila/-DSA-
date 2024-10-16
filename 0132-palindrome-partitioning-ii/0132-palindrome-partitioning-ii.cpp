class Solution {
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(int i, int j, const string &s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Helper function to find the minimum cuts using memoization
    int solve(int i, int j, const string &s, vector<vector<int>> &dp) {
        if (i >= j || isPalindrome(i, j, s))  // If already a palindrome or a single character
            return 0;

        if (dp[i][j] != -1)  // Check if this subproblem has already been solved
            return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            if (isPalindrome(i, k, s)) {  // Only partition if the left part is a palindrome
                int rightPart = solve(k + 1, j, s, dp);
                mini = min(mini, 1 + rightPart);
            }
        }

        dp[i][j] = mini;  // Store the result in the memoization table
        return dp[i][j];
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // Initialize memoization table
        return solve(0, n - 1, s, dp);
    }
};
