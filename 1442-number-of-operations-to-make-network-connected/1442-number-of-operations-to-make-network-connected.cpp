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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        int extra=0;
        Disjointset ds(n);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(ds.findUpar(u)!=ds.findUpar(v))
            {
                ds.unionBysize(u,v);
            }else
            extra++;
            
            
        }
        int no=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            no++;
            
        }
        
        int ans=no-1;
        if(extra>=ans)
        return ans;
        else
        return -1;
        
    }
};