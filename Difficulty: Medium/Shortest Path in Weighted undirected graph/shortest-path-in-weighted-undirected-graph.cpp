//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<int> dis(n+1,1e9);
        vector<int> path(n+1);
        
        for(int i=1;i<=n;i++)
        path[i]=i;
        
        vector<pair<int,int>> adj[n+1];
        
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        dis[1]=0;
        path[1]=1;
        
        
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                
                if(wt+adjwt<dis[adjnode])
                {
                    dis[adjnode]=wt+adjwt;
                    pq.push({dis[adjnode],adjnode});
                    path[adjnode]=node;
                }
            }
        }
        
   
        
        
        vector<int> ans;
        int ind=n;
        
        if(dis[n]==1e9)
        return {-1};

        while(path[ind]!=ind)
        {
            ans.push_back(ind);
            ind=path[ind];
        }
        ans.push_back(1);
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        
        return ans;
        

        
        
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends