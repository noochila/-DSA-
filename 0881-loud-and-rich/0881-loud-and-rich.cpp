class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();

        // Step 1: Build the adjacency list and indegree array.
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for (const auto& it : richer) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        // Step 2: Initialize the answer array to point to self initially.
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = i;  // Start by assuming each person is their own quietest
        }

        // Step 3: Topological sorting using BFS
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            // For each neighbor `v` of `u`, propagate the quietest person
            for (int v : adj[u]) {
                // If the person reachable from `u` is quieter, update `ans[v]`
                if (quiet[ans[u]] < quiet[ans[v]]) {
                    ans[v] = ans[u];
                }
                
                // Decrement the indegree of `v`
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return ans;
    }
};
