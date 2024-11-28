class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));

        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        vis[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int dis = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            if (x == n - 1 && y == m - 1) {
                return dis;
            }

            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m)
                {
                    if(vis[nx][ny]==-1)
                    {
                        if(grid[nx][ny]==0)
                        {
                            pq.push({dis,{nx,ny}});
                            vis[nx][ny]=dis;
                        }else
                        {
                            pq.push({dis+1,{nx,ny}});
                            vis[nx][ny]=1+dis;
                        }
                    }else
                    {
                        if(grid[nx][ny]==0)
                        {
                            if(vis[nx][ny]>dis)
                            {
                                pq.push({dis,{nx,ny}});
                                vis[nx][ny]=dis;
                            }
                        }else
                        {
                            if(vis[nx][ny]>1+dis)
                            {
                                pq.push({dis+1,{nx,ny}});
                                vis[nx][ny]=1+dis;
                            }
                        }
                    }
                }
            }
        }
        return vis[n-1][m-1];
    }
};