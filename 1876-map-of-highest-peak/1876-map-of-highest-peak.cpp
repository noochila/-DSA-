class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        queue<pair<int,pair<int,int>>>q;


        vector<vector<int>> vis(n,vector<int>(m,-1));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=0;

                }
            }
        }


        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();

            int x=temp.second.first;
            int y=temp.second.second;

        

            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};

            for(int k=0;k<4;k++)
            {
                int rx=dx[k]+x;
                int ry=dy[k]+y;

                if(  rx>=0 && rx<n && ry>=0 && ry<m && vis[rx][ry]==-1  )
                {
                    vis[rx][ry]=temp.first+1;
                    q.push({temp.first+1,{rx,ry}});
                    
                }
            }
        }

        return vis;
        
        
    }
};