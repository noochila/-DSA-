class Solution {
public:
    int solve1(int i, int j, vector<vector<int>>& fruits,
               vector<vector<int>>& dp1) {
        int n = fruits.size();
        if (i == n - 1 && j == n - 1)
            return 0;

        if (i >= n || i < 0 || j >= n || j < 0 || i>=j)
            return -1e9;

        if (dp1[i][j] != -1)
            return dp1[i][j];

        int move1 = fruits[i][j] + solve1(i + 1, j - 1, fruits, dp1);
        int move2 = fruits[i][j] + solve1(i + 1, j, fruits, dp1);
        int move3 = fruits[i][j] + solve1(i + 1, j + 1, fruits, dp1);

        return dp1[i][j] = max({move1, move2, move3});
    }

    int solve2(int i, int j, vector<vector<int>>& fruits,
               vector<vector<int>>& dp2) {
        int n = fruits.size();
        if (i == n - 1 && j == n - 1)
            return 0;

        if (i >= n || i < 0 || j >= n || j < 0 || i<=j )
            return -1e9;

        if (dp2[i][j] != -1)
            return dp2[i][j];

        int move1 = fruits[i][j] + solve2(i + 1, j + 1, fruits, dp2);
        int move2 = fruits[i][j] + solve2(i, j+1, fruits, dp2);
        int move3 = fruits[i][j] + solve2(i - 1, j + 1, fruits, dp2);

        return dp2[i][j] = max({move1, move2, move3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            ans1 += fruits[i][i];
            // fruits[i][i] = 0;
        }

        int ans2 = solve1(0, n - 1, fruits, dp1);
        int ans3 = solve2(n - 1, 0, fruits, dp2);


        return ans1 + max(0, ans2) + max(0, ans3);
    }
};
