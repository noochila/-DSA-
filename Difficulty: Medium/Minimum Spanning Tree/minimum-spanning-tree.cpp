//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset
{
    public:
    vector<int> rank,parent,size;
    Disjointset(int n)
    {
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++)
        parent[i]=i;

    }
    int findUpar(int u)
    {
        if(parent[u]==u)
        return u;
        return parent[u]=findUpar(parent[u]);
    }

    void unionByrank(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)
        return ;

        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;

        }else{
             parent[ulp_v]=ulp_u;
             rank[ulp_u]++;

        }
    }

    void unionBysize(int u,int v)
    {
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);

        if(ulp_u==ulp_v)
        return ;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
             parent[ulp_v]=ulp_u;
           size[ulp_u]+=size[ulp_v];

        }
        
    }

};
class Solution
{
	public:
	
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
    //       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
    //     int min=0;
        
    //     pq.push({0,{0,-1}});
    //     vector<int> vis(V,0);
        
    //      vector<pair<int,int>>mst;
        
    //     while(!pq.empty())
    //     {
    //         auto temp=pq.top();
    //         pq.pop();
            
    //         int node=temp.second.first;
    //         int par=temp.second.second;
    //         int val=temp.first;
            
      
            
    //         if(vis[node]==1)
    //         continue;
            
    //         vis[node]=1;
            
            
    //         if(par!=-1)
    //         {
            
    //             mst.push_back({par,node});
    //         }
    //               min+=val;
            
    //         for(auto it:adj[node])
    //         {
    //             if(!vis[it[0]])
    //             {
    //                 pq.push({it[1],{it[0],par}});
    //             }
                
    //         }
            
    //     }
        
    // //  for(auto it:mst)
    // //  cout<<it.first<<" "<<it.second<<endl;
        
    //      return min;
    
    
    
    vector<pair<int,pair<int,int>>> edges;
    
    for(int i=0;i<V;i++){
    for(auto it:adj[i])
    {
        edges.push_back({it[1],{it[0],i}});
        
    }}
    
    
    sort(edges.begin(),edges.end());
    
    Disjointset ds(V);
    int min=0;
    
    for(auto it:edges)
    {
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        
        if(ds.findUpar(u)!=ds.findUpar(v))
        {
            min+=wt;
            ds.unionBysize(u,v);
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