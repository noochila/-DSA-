class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
           int n=matrix.size();
           int m=matrix[0].size();

        int negetivecount=0;
        int adjacent=0;
        long long sum=0;
        int mini=1e9;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0)
                negetivecount++;

                sum+=abs(matrix[i][j]);
                mini=min(mini,abs(matrix[i][j]));
            }
        }

        if(negetivecount%2==0)
        {
            return sum;

        }else
        {
            return sum-2*mini;
        }


        
    }
};