class Solution {
public:

    void bfs(int i,int j,vector<vector<int>>&vis,int c,vector<vector<int>>&image,vector<vector<int>>&ans)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int m=image[i][j];
        ans[i][j]=c;

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int k=0;k<4;k++)
            {
               int rx=x+dx[k];
               int  ry=y+dy[k];

                if(rx>=0 && rx<image.size() &&  ry>=0 && ry<image[0].size() && image[rx][ry]==m && vis[rx][ry]==0)

                {
                   ans[rx][ry]=c;
                   vis[rx][ry]=1;
                   q.push({rx,ry});
                }
            }
        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n=image.size();
        int m=image[0].size();


        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>>ans(image);

        bfs(sr,sc,vis,color,image,ans);

        return ans;

        
        
    }
};