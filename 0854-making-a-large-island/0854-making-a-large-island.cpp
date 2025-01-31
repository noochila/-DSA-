class DisjointSet {
public: 
    vector<int> parent, size; 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto it:dir){
                        int adjR=it.first+i,adjC=it.second+j;
                        if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]){
                            ds.unionBySize(n*adjR + adjC , n*i + j);
                        } 
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(auto it:dir){
                        int adjR=it.first+i,adjC=it.second+j;
                        if(adjR>=0 && adjR<n && adjC>=0 && adjC<n && grid[adjR][adjC]){
                            st.insert(ds.findUPar(n*adjR+adjC));
                        }
                    }
                    int tmp_size=1;
                    for(auto it:st){
                        tmp_size+=(ds.size[it]);
                    }
                    ans=max(ans,tmp_size);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};
