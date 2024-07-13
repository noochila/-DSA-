class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
       
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int time = temp.first;
            int i = temp.second.first;
            int j = temp.second.second;

            if (i == n - 1 && j == n - 1) return time;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]) {
                    vis[x][y] = 1;
                    pq.push({max(time, grid[x][y]), {x, y}});
                }
            }
        }
        return -1;
    }
};
