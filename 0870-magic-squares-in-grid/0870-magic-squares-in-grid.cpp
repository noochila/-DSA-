class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        vector<int> count(16, 0); // To count occurrences of numbers 1-9
        
        // Check all numbers are in the range 1 to 9 and are distinct
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || count[num] != 0)
                    return false;
                count[num]++;
            }
        }
        
        // Check rows, columns and diagonals
        int sum1 = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        int sum2 = grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2];
        int sum3 = grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2];
        int sum4 = grid[r][c] + grid[r+1][c] + grid[r+2][c];
        int sum5 = grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1];
        int sum6 = grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2];
        int diag1 = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int diag2 = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];
        
        return (sum1 == 15 && sum2 == 15 && sum3 == 15 &&
                sum4 == 15 && sum5 == 15 && sum6 == 15 &&
                diag1 == 15 && diag2 == 15);
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        // Iterate over all possible top-left corners of 3x3 subgrids
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
