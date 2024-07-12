class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;

       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       

       pq.push({1,{0,0}});
       grid[0][0]=1;
         vector<vector<int>> dist(n,vector<int>(n,1e9));

         dist[0][0]=1;


       while(!pq.empty())
       {
        auto temp=pq.top();
        pq.pop();

      

        int i=temp.second.first;
        int j=temp.second.second;

        int dis=temp.first;


        for(int dx=-1;dx<=1;dx++)
        {
            for(int dy=-1;dy<=1;dy++)
            {
                if( dx+i>=0 && dx+i<n && dy+j>=0 && dy+j<n  && grid[dx+i][dy+j]!=1)
                {
                        if(dis+1<dist[dx+i][dy+j])
                        {
                            dist[dx+i][dy+j]=1+dis;
                            pq.push({dist[dx+i][dy+j],{dx+i,dy+j}});
                           grid[dx+i][dy+j]=1;
                        }
                }
            }
        }

       }
        return dist[n-1][n-1]==1e9?-1:dist[n-1][n-1];
         

    }
};