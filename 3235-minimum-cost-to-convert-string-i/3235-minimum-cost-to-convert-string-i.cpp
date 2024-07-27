typedef pair<int,int> pii;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& O, vector<char>& C, vector<int>& cost) {
        vector<vector<pii>> adj(26);
        for (int i = 0; i < O.size(); i++) {
            adj[O[i]-'a'].push_back({C[i]-'a', cost[i]});
        }
        
        vector<vector<int>> memo(26, vector<int>(26, -1));
        
        function<int(int,int)> dijkstra = [&](int s, int e) {
            if (memo[s][e] != -1) return memo[s][e];
            
            int n = adj.size();
            vector<int> dist(n, INT_MAX);
            dist[s] = 0;

            priority_queue<pii, vector<pii>, greater<pii>> minq;
            minq.push({0, s});

            int u, v, w;
            while (!minq.empty()) {
                auto p = minq.top(); minq.pop();
                u = p.second;

                if (dist[u] < p.first)
                    continue;

                if (u == e)
                    return memo[s][e] = p.first;

                for (auto& node: adj[u]) {
                    v = node.first, w = node.second;
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        minq.push({dist[v], v});
                    }
                }
            }
            return memo[s][e] = (dist[e] == INT_MAX ? -2 : dist[e]);
        };
        
        long long res = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int c = dijkstra(source[i]-'a', target[i]-'a');
                if (c < 0) return -1;
                res += c;
            }
        }
        return res;
    }
};