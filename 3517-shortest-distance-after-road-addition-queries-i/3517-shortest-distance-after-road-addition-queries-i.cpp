#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }
        
        
        auto bfs = [&](int start, int end) -> int {
            vector<int> distance(n, INT_MAX);
            queue<int> q;
            
          
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

      
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            
            adj[u].push_back(v);

            
            result.push_back(bfs(0, n - 1));
        }

        return result;
    }
};
