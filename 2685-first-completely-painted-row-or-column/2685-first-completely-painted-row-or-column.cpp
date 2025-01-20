class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        map<int,int>mp;

        for(int i=0;i<arr.size();i++)
        mp[arr[i]]=i;

        int ans=1e9;

        for(int i=0;i<mat.size();i++)
        {
            int maxi=0;
            for(int j=0;j<mat[0].size();j++)
            {
                maxi=max(maxi,mp[mat[i][j]]);

            }
            ans=min(ans,maxi);


        }

         for(int i=0;i<mat[0].size();i++)
        {
            int maxi=0;
            for(int j=0;j<mat.size();j++)
            {
                maxi=max(maxi,mp[mat[j][i]]);

            }
            ans=min(ans,maxi);


        }
        return ans;

        
        
    }
};