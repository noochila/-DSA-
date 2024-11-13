class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        
        // Step 1: Build the adjacency list and indegree array.
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for (const auto& r : richer) {
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }

        // Step 2: Initialize the answer array with self as the quietest initially.
        vector<int> answer(n);
        for (int i = 0; i < n; ++i) answer[i] = i;

        // Step 3: Process nodes in topological order using BFS.
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            // For each person `v` who is poorer than `u`
            for (int v : adj[u]) {
                // Update answer for `v` if `u` has a quieter person
                if (quiet[answer[u]] < quiet[answer[v]]) {
                    answer[v] = answer[u];
                }
                
                // Decrement indegree and add to queue if `v` becomes 0
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return answer;
    }
};
