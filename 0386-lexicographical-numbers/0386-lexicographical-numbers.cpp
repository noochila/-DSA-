class Solution {
public:
    vector<int> ans;

    // Helper function for DFS
    void dfs(int temp, int n) {
        // If the current number exceeds n, stop the recursion
        if (temp > n) {
            return;
        }

        // Store the current number in the result
        ans.push_back(temp);

        // Try appending digits 0 through 9 to the current number
        for (int i = 0; i <= 9; i++) {
            int nextNum = temp * 10 + i; // Form the next number by appending i
            if (nextNum > n) {
                break; // If the next number exceeds n, stop further recursion
            }
            dfs(nextNum, n); // Recursively call DFS for the next number
        }
    }

    vector<int> lexicalOrder(int n) {
        // Start DFS from numbers 1 through 9 (since lexicographically ordered numbers start from 1)
        for (int i = 1; i <= 9; i++) {
            dfs(i, n);
        }

        return ans; // Return the result after DFS completes
    }
};
