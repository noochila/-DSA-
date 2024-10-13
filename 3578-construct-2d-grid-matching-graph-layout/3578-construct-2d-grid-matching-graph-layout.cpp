class Solution {
public:
    vector<int> getPath(int src, int dest, vector<int> adj[], int n) {

        auto bfs = [&](int src, int n) {
            vector<int> dist(n, -1), from(n, -1);
            queue<int> q;
            dist[src] = 0;
            q.push(src);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        from[v] = u;
                        q.push(v);
                    }
                }
            }
            return from;
        };

        vector<int> from = bfs(src, n), path;
        for (int node = dest; node != -1; node = from[node])
            path.push_back(node);

        reverse(path.begin(), path.end());
        return path;
    }
    vector<vector<int>> handle1dimenstion(vector<int> adj[], int n) {

        int src = -1, dest = -1;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 1)
                continue;
            if (src == -1)
                src = i;
            else if (dest == -1)
                dest = i;
        }
        if (dest == -1)
            return {};
        vector<int> path = getPath(src, dest, adj, n);
        return {path};
    }

    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> ans = handle1dimenstion(adj, n);
        if(!ans.empty())
        return ans;
         
          vector<int> corners;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 2) continue;
            corners.push_back(i);
        }

             vector<int> paths_size = {
            static_cast<int>(getPath(corners[0], corners[1], adj,n).size()),
            static_cast<int>(getPath(corners[0], corners[2], adj,n).size()),
            static_cast<int>(getPath(corners[0], corners[3], adj,n).size())
        };
        int minIndex = min_element(paths_size.begin(), paths_size.end()) - paths_size.begin();
        int cols = paths_size[minIndex];
        int rows = n / cols;

         ans = vector<vector<int>>(rows, vector<int>(cols, -1));
         ans[0] = getPath(corners[0], corners[minIndex + 1], adj,n);

         for (int r = 0; r < rows - 1; r++) {
            for (int c = 0; c < cols; c++) {
                // Find the neighbors that have already been placed.
                set<int> neighbors;
                if (r > 0) neighbors.insert(ans[r - 1][c]);
                if (c > 0) neighbors.insert(ans[r][c - 1]);
                if (c + 1 < cols) neighbors.insert(ans[r][c + 1]);
                
                // Place the neighbor that has not been placed yet.
                int u = ans[r][c];
                for (int v : adj[u]) {
                    if (!neighbors.contains(v)) {
                        ans[r + 1][c] = v;
                        break;
                    }
                }
            }
        }
        
        return ans;


        

        





    }
};