#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {

        int n = edges1.size() + 1;
        int m = edges2.size() + 1; 


        auto build = [&](vector<vector<int>>& edges, int nodes) -> vector<vector<int>> {
            vector<vector<int>> adj(nodes);
            for (auto& edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            return adj;
        };

        vector<vector<int>> adj1 = build(edges1, n);
        vector<vector<int>> adj2 = build(edges2, m);

        vector<unordered_set<int>> store1(n);
        vector<unordered_set<int>> store2(m);

    
        auto bfs = [&](vector<vector<int>>& adj, int k, int start) -> unordered_set<int> {
            unordered_set<int> visited;
            queue<pair<int, int>> q;
            q.push({start, 0}); 
            visited.insert(start);

            while (!q.empty()) {
                auto [node, dist] = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited.count(neighbor) && dist + 1 <= k) {
                        visited.insert(neighbor);
                        q.push({neighbor, dist + 1});
                    }
                }
            }

            return visited;
        };

        
        for (int i = 0; i < n; i++) {
            store1[i] = bfs(adj1, k, i);
        }
        for (int i = 0; i < m; i++) {
            store2[i] = bfs(adj2, k - 1, i);
        }

        vector<int> ans(n, 0);

      
        if (k == 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = store1[i].size();
            }
            return ans;
        }

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int totalNodes = store1[i].size() + store2[j].size();
                ans[i] = max(ans[i], totalNodes);
            }
        }

        return ans;
    }
};
