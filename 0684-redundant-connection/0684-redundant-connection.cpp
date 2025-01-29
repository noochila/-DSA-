#include<bits/stdc++.h>
#include<vector>

using namespace std;
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
        }
          

        else{
             parent[ulp_v]=ulp_u;
               size[ulp_u]+=size[ulp_v];

        }
        
    }

};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();

        Disjointset ds(n);

        vector<int>ans;
        
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUpar(u)==ds.findUpar(v))
            {
                ans.push_back(u);
                ans.push_back(v);
                return ans;
            }else
            {
                ds.unionBysize(u,v);
            }
        }

        return {};
        
    }
};