class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // int n;
        // for(auto it:edges)
        // n=max(it[0],max(it[1],n));

        // vector<int> adj[n];


        // for(auto it:edges)
        // {
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        //  int ind=-1;
        // for(int i=0;i<n;i++)
        // {
        //         if(adj[i].size()==n-1)
        //         ind=i;
        // }
        // return ind;
            if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];

    }
};