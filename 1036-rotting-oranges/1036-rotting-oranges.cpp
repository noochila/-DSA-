class Solution {
public:
int maxtime=0;


    int orangesRotting(vector<vector<int>>& grid) {

        int t=0;

       int n=grid.size();
       int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
     queue<pair<int,pair<int,int>>>q;


       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==2 && vis[i][j]==0 )
               {
                   q.push({t,{i,j}});
                    vis[i][j]=2;
               }
           }
       }


       
      
      

        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.second.first;
            int y=temp.second.second;
              maxtime=max(maxtime,temp.first);
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

         

            for(int k=0;k<4;k++)
            {
               int rx=x+dx[k];
               int  ry=y+dy[k];

               
              

                if(rx>=0 && rx<grid.size() &&  ry>=0 && ry<grid[0].size() && grid[rx][ry]==1 && vis[rx][ry]==0)

                {
                     
                   vis[rx][ry]=2;
                   q.push({temp.first+1,{rx,ry}});
                }
            }
        }


        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(grid[i][j]==1)
               { 
                   if(vis[i][j]==0)
                   return -1;
                  
               }
           }
       }
      
       return maxtime;


        


        
    }
};