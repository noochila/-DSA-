class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> indegree;
        map<int, int> outdegree;
        map<int, vector<int>> adj;
        
        for (auto it : pairs) {
            indegree[it[1]]++;
            outdegree[it[0]]++;
            adj[it[0]].push_back(it[1]);
        }

        int start = pairs[0][0]; 

        
        for (auto it : pairs) {
            if (outdegree[it[0]] - indegree[it[0]] == 1) {
                start = it[0];
                break;
            }
        }

        vector<int> ans;
        auto dfs = [&](int node, auto&& self) -> void {
            while (!adj[node].empty()) { 
                int next = adj[node].back();
                adj[node].pop_back();
                self(next, self);
            }
            ans.push_back(node); 
        };

        dfs(start, dfs);
        reverse(ans.begin(), ans.end());

       
        vector<vector<int>> result;
        for (int i = 0; i < ans.size() - 1; ++i) {
            result.push_back({ans[i], ans[i + 1]});
        }

        return result;
    }
};
