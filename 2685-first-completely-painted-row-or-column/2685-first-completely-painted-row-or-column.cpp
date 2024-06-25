class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        map<int,int>mp;

        for(int i=0;i<arr.size();i++)
        mp[arr[i]]=i;


        int ans=1e9;

        for(int i=0;i<n;i++)
        {
            int c=0;
            for(int j=0;j<m;j++)
            c=max(c,mp[mat[i][j]]);

            ans=min(ans,c);
        }
        for(int i=0;i<m;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            c=max(c,mp[mat[j][i]]);

            ans=min(ans,c);
        }
        return ans;
        
    }
};