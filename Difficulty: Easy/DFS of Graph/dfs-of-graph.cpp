//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    
    
    void dfs(int i,vector<vector<int>>&adj,vector<int>&ans,vector<int>&vis)
    {
        ans.push_back(i);
        vis[i]=1;
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,adj,ans,vis);
        }
    }
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        
        vector<int> ans;
        
        int n=adj.size();
       vector<int>vis(n,0);
       
       for(int i=0;i<n;i++)
       {
           if(!vis[i])
         {  dfs(i,adj,ans,vis);
            
         }
       }
       
    return ans;  
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends