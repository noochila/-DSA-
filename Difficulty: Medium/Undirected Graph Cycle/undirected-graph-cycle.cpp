//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
 bool cycleDetect(int node, int parent, vector<int> adj[], vector<bool> &visited)
    {

        visited[node] = 1;
        for (auto it : adj[node])
        {   
            // for node 0 ,it=1 an parent =-1
            // for node 1, it=0 and parent =0 
            if (parent == it)
                continue;
            if (visited[it])
                return 1;
            if (cycleDetect(it, node, adj, visited))
                return 1;
        }
        return 0;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if (cycleDetect(i, -1, adj, visited))
                    return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends