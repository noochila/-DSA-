//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        int min=0;
        
        pq.push({0,{0,-1}});
        vector<int> vis(V,0);
        
         vector<pair<int,int>>mst;
        
        while(!pq.empty())
        {
            auto temp=pq.top();
            pq.pop();
            
            int node=temp.second.first;
            int par=temp.second.second;
            int val=temp.first;
            
      
            
            if(vis[node]==1)
            continue;
            
            vis[node]=1;
            
            
            if(par!=-1)
            {
            
                mst.push_back({par,node});
            }
                  min+=val;
            
            for(auto it:adj[node])
            {
                if(!vis[it[0]])
                {
                    pq.push({it[1],{it[0],par}});
                }
                
            }
            
        }
        
   
        
         return min;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends