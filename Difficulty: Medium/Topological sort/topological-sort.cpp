//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 

vector<int> topoSort(int V, vector<int> adj[]) 
{
    // Initialize the indegree vector with 0 for all vertices
    vector<int> indegree(V, 0);
    
    // Calculate the indegree of each vertex
    for(int i = 0; i < V; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    
    // Queue to store vertices with 0 indegree
    queue<int> q;
    
    // Push all vertices with 0 indegree to the queue
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    // Vector to store the topological order
    vector<int> ans;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        // Add the node to the topological order
        ans.push_back(node);
        
        // Decrease the indegree of the adjacent vertices
        for(auto it : adj[node])
        {
            indegree[it]--;
            // If indegree becomes 0, add it to the queue
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    
    return ans;
}

};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends