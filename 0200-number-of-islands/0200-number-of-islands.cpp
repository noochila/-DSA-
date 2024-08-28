class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& roads,
             vector<vector<int>>& visited, int n, int m) {

        visited[i][j] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {

            int nrow = drow[k] + i;
            int ncol = dcol[k] + j;

            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                roads[nrow][ncol] == '1' && visited[nrow][ncol] == 0)
                dfs(nrow, ncol, roads, visited, n, m);
        }
    }

    
    int findNumOfProvinces(vector<vector<char>>& roads, int n, int m) {
    // Write your code here.

    int count = 0;

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && roads[i][j] == '1') {

                dfs(i, j, roads, visited, n, m);
                count++;
            }
        }
    }

    return count;
}
int numIslands(vector<vector<char>>& grid) {
    return findNumOfProvinces(grid, grid.size(), grid[0].size());
}
}
;