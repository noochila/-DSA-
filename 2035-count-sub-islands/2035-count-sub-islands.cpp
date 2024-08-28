class Solution {
public:
    vector<int>a={0,1,-1,0};
    vector<int>b={1,0,0,-1};
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis,int x,int y,int &flag){
        vis[x][y]=1;
        if(grid1[x][y]!=1){
            flag=0;
        }
        for(int i=0;i<4;i++){
            int ax=x+a[i];
            int ay=y+b[i];
            if(ax>=0&&ay>=0&&ax<grid1.size()&&ay<grid1[0].size()&&grid2[ax][ay]==1&&!vis[ax][ay]){
                dfs(grid1,grid2,vis,ax,ay,flag);
            }
        }
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          int n=grid1.size();
          int m=grid1[0].size();
          vector<vector<int>>vis(n+1,vector<int>(m+1,0));
          int ans=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                 if(!vis[i][j]&&grid2[i][j]==1&&grid1[i][j]==1){
                   int flag=1;
                   dfs(grid1,grid2,vis,i,j,flag);
                   if(flag) ans++;
                 }
              }
          }
          return ans;
    }
};