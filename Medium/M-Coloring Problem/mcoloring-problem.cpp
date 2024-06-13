//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    vector<int> color;
    
    bool check(vector<int> adj[],int c,int node)
    {
        
        for(auto it:adj[node])
        {
            if(color[it]==c)
            return false;
        }
        
        return true;
        
    }
    
    bool  solve( int m, int n,int node,vector<int>adj[])
    {
        
        if(node==n)
        return true;
        
        
        for(int c=1;c<=m;c++)
        {
            if(check(adj,c,node))
            {
                color[node]=c;
                if(solve(m,n,node+1,adj))
                return true;
                color[node]=-1;
                
            }
            
            
        }
        return false;
    
    }
    
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        
        
        
        
        // your code here
        color.resize(n,-1);
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
      {  
          for(int j=0;j<n;j++)
      {  
          if(graph[i][j]==1)
          {
              adj[i].push_back(j);
          }
      }
          
      }
        
        
        
       
       
       if(solve(m,n,0,adj))
       return true;
       
       
       return false;
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends