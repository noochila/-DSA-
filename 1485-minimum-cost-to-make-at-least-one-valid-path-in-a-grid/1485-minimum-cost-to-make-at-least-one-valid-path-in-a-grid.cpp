class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Visited grid
        pq.push({0, {0, 0}});

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int x = temp.second.first;
            int y = temp.second.second;
            int cost = temp.first;

            if (x == n - 1 && y == m - 1) // Destination reached
                return cost;

            if (visited[x][y]) // Skip if already visited
                continue;

            visited[x][y] = 1; // Mark as visited

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int newCost = cost + (grid[x][y] != k + 1);

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
        return 0; // Unreachable case (shouldn't happen with valid input)
    }
};
