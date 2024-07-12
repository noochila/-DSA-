// class Solution {
// public:

//   bool dfs(int s,vector<int>&vis,vector<int>&path,vector<vector<int>>& graph)
//   {
//       vis[s]=1;

//       path[s]=1;

//       for(auto it:graph[s])

//      {
//          if(!vis[it])
//          {
//             if(dfs(it,vis,path,graph)==true)
//             return true;

//          }else if(path[it])
//          {
//            return true;

//          }
//      }

//       path[s]=0;
//       return false;
//   }
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n=graph.size();

//         vector<int> vis(n,0);
//         vector<int> path(n,0);

//         for(int i=0;i<n;i++)
//         {
//             if(!vis[i])
//             dfs(i,vis,path,graph);

//         }

//         vector<int> ans;

//         for(int i=0;i<n;i++)
//         {
//             if(path[i]==0)
//             ans.push_back(i);
//         }
//         sort(ans.begin(),ans.end());
//         return ans;

//     }
// };

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