class Solution {
public:
    void dfs(int node, const vector<int> graph[], set<int>& visited) {
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& a) {
        vector<int> adj[n];
        for (auto it : a) {
            adj[it[0]].push_back(it[1]);
        }

        set<int> temp;
        dfs(k, adj, temp);
        vector<int> sus(temp.begin(), temp.end());

        map<int, int> mp;
        for (auto it : sus) {
            mp[it]++;
        }

        set<int> ans;
        bool canRemove = true;

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                if (mp.find(i) == mp.end() && mp.find(it) != mp.end()) {
                    canRemove = false;
                    break;
                }
            }
            if (!canRemove) break;
        }

        if (!canRemove) {
            vector<int> allMethods;
            for (int i = 0; i < n; i++) {
                allMethods.push_back(i);
            }
            return allMethods;
        }

        for (int i = 0; i < n; i++) {
            if (mp.find(i) == mp.end()) {
                ans.insert(i);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};
