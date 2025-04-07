//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<int>&vis,int i,vector<int>adj[],vector<int>&pathVis)
    {
        vis[i]=1;
        pathVis[i]=1;
        
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(vis,it,adj,pathVis))
                return true;
            }else if(vis[it] && pathVis[it])
            return true;
        }
        
        pathVis[i]=0;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        
        // code here
        
        vector<int>adj[V];
        for(auto it:edges)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
        }
        
        
         vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                 if( dfs(vis,i,adj,pathVis))
                 return true;
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends