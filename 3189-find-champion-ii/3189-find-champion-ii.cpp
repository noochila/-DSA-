class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }

        int count = 0;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                idx = i;
            }
        }

        if (count > 1)
            return -1;
        else
            return idx;
    }
};