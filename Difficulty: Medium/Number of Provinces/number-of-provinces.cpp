//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
    void dfs(int i,int V,vector<int>adj[],vector<int>&vis)
    {
        vis[i]=1;
        
        
        for(auto it:adj[i])
        {
            if(!vis[it])
            dfs(it,V,adj,vis);
        }
    }
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        
        
        vector<int> adjList[V];
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,V,adjList,vis);
                count++;
            }
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends