class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    int trapRainWater(vector<vector<int>>& heightMap) {

        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<p, vector<p>, greater<>> pq;

        vector<vector<int>> vis(n, vector<int>(m, false));

        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m - 1], {i, m - 1}});
            vis[i][0] = true;
            vis[i][m - 1] = true;
        }

        for (int j = 0; j < m; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n - 1][j], {n - 1, j}});
            vis[0][j] = true;
            vis[n - 1][j] = true;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int ans = 0;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int h = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    int curr = max(0, h - heightMap[nx][ny]);
                    ans += curr;
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return ans;
    }
};