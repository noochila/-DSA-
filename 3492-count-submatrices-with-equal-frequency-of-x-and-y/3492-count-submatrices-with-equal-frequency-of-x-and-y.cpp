#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        // Prefix sums for 'X' and 'Y'
        vector<vector<int>> prefixX(n + 1, vector<int>(m + 1, 0));
        vector<vector<int>> prefixY(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                prefixX[i][j] = prefixX[i - 1][j] + prefixX[i][j - 1] - prefixX[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                prefixY[i][j] = prefixY[i - 1][j] + prefixY[i][j - 1] - prefixY[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }

        // Iterate over all possible submatrices starting from (1, 1)
        // Check all possible submatrices that include grid[0][0]
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int x = prefixX[i][j];
                int y = prefixY[i][j];
                if (x == y && x > 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
      
};
