class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {



        int n=a.size();
        int m=a[0].size();

       priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;

        q.push({0,{0,0}});

        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};

        vis[0][0]=0;
        while(!q.empty())
        {
            auto temp=q.top();
            q.pop();

            int t=temp.first;
            int x=temp.second.first;
            int y=temp.second.second;

           

            if(x==n-1 && y==m-1)
            {
                return t;
            }


            for(int k=0;k<4;k++)
            {
                int  nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m )
                {
                    int nextTime = max(t, a[nx][ny] )+1;

                    if(nextTime<vis[nx][ny])
                    {
                        vis[nx][ny]=nextTime;
                        q.push({nextTime,{nx,ny}});
                    }


                }
            }

        }

        return -1;
            
    }
};