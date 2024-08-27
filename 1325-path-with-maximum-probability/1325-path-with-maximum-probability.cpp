class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {

        vector<double> dis(n, 0.0);  // Initialize distances with 0.0

        vector<pair<int, double>> adj[n];

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        dis[start_node] = 1.0;  // Starting node probability is 1.0

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            double currProb = temp.first;
            int node = temp.second;

            if (node == end_node)
                return currProb;

            for (auto it : adj[node]) {
                int nextNode = it.first;
                double edgeProb = it.second;

                if (currProb * edgeProb > dis[nextNode]) {
                    dis[nextNode] = currProb * edgeProb;
                    pq.push({dis[nextNode], nextNode});
                }
            }
        }

        return 0.0;  // If no path is found
    }
};
