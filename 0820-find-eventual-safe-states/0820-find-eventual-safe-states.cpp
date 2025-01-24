class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int numCourses = graph.size();

        vector<int> adj[numCourses];
    
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {


            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;

            }

          
            
        }


        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};