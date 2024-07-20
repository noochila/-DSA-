class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();

        int i=0;
        int j=0;

        vector<vector<int>> vis(n,vector<int>(m,0));

        while(i<n && j<m)
        {
            vis[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=vis[i][j];
            colSum[j]-=vis[i][j];
            if(rowSum[i]==0)
            i++;
            else
            j++;
        }
        return vis;
        
    }
};