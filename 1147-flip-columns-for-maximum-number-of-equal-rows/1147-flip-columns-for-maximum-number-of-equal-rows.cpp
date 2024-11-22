class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int> inverted(m);
            for(int j=0;j<m;j++)
            inverted[j]=(1-matrix[i][j]);
            int c=0;

            for(auto row : matrix)
            {
                if(row==matrix[i] || row==inverted)
                c++;

            }
            ans=max(ans,c);
        }

        return ans;
    }
};