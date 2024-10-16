class Solution {
public:



    int solve(int i,int j,string &source,string &pattern,set<int>&s, vector<vector<int>> &dp)
    {

        if(j==pattern.size())
        {
           int c=0;
           for(auto it:s)
           {
            if(it>=i)
            c++;
           }
           return c;
        }

        if(i==source.size())
        return -1e9;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int res=0;

        if(s.find(i)==s.end())
        {
            if(source[i]==pattern[j])
                res=solve(i+1,j+1,source,pattern,s,dp);
            else
            res=solve(i+1,j,source,pattern,s,dp);
        }
        else
        {
             int pc=1+solve(i+1,j,source,pattern,s,dp);
             int skip=0;

             if(source[i]==pattern[j])
             
            skip=solve(i+1,j+1,source,pattern,s,dp);
             else
             skip=solve(i+1,j,source,pattern,s,dp);

             res=max(skip,pc);

            
        }

        return dp[i][j]=res;
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
         set<int>s(targetIndices.begin(),targetIndices.end());
         int n=source.size();
         int m=pattern.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        int res= solve(0,0,source,pattern,s,dp);

        if(res<=0)
        return 0;
        return res;







    }
};