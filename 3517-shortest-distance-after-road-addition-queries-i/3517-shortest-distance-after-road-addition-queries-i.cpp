#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list representation
        vector<vector<int>> adj(n);
        
        // Initialize the graph with unidirectional edges from i to i + 1
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        
        // Function to calculate shortest path using BFS
        auto bfs = [&](int start, int end) -> int {
            vector<int> distance(n, INT_MAX);
            queue<int> q;
            
            // Start BFS from `start` node
            q.push(start);
            distance[start] = 0;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : adj[curr]) {
                    if (distance[neighbor] == INT_MAX) {
                        distance[neighbor] = distance[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }
            
            return distance[end];
        };

        vector<int> result;

        // Process each query
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            // Add the new road
            adj[u].push_back(v);

            // Calculate the shortest path from city 0 to city n - 1
            result.push_back(bfs(0, n - 1));
        }

        return result;
    }
};
