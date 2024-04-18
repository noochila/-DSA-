class Solution {
public:
    void bfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, int& ans) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            int dx = temp.first;
            int dy = temp.second;

            int fx[] = {1, 0, -1, 0};
            int fy[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nx = dx + fx[k];
                int ny = dy + fy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    ans++;
                } else if (grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                } else if (grid[nx][ny] == 0) {
                    // This is a water cell, contribute to perimeter
                    ans++;
                }
            }
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j, visited, grid, ans);
                }
            }
        }

        return ans;
    }
};
