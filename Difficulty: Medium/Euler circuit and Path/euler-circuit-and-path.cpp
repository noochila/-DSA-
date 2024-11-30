//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


   void dfs(vector<bool>&vis,vector<int> adj[],int i)
   {
       vis[i]=true;
       for(auto it:adj[i])
       {
           if(!vis[it])
           {
               dfs(vis,adj,it);
           }
       }
       
   }

	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    
	    
	    vector<int> indegree(V,0);
	    
	 for(int i=0;i<V;i++)
	 {
	     for(auto j:adj[i])
	     {
	         indegree[j]++;
	         
	     }
	     
	    
	 }
	 int c=0;
	    
	    
	    vector<bool> vis(V,false);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(vis,adj,i);
	            c++;
	            
	            
	            
	            
	        }
	    }
	    
	    
	    int zero=0;
	    for(int i=0;i<V;i++)
	    {
	        if(adj[i].size()==0)
	        zero++;
	    }
	    
	    if(zero==(c-1))
	    {
	        
	        int oddcount=0;
	            int evencount=0;
	            
	            for(int j=0;j<V;j++)
	            {
	                if(vis[j])
	                {
	                    if(indegree[j]%2)
	                    oddcount++;
	                    else
	                    evencount++;
	                    
	                }
	            }
	            
	           // for(auto it:indegree)
	           // cout<<it<<" ";
	            
	           // cout<<endl;
	            
	            if(oddcount>2)
	            return 0;
	            else if(oddcount==2)
	            return 1;
	            else if(evencount==V)
	            return 2;
	            else
	            return 0;
	            
	        
	    }else
	    return 0;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends