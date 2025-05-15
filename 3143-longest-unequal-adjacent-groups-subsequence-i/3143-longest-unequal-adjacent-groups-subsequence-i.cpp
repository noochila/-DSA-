class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {


       int n=words.size();

       vector<int> dp(n,1);
       vector<int> path(n,-1);


       for(int i=0;i<n;i++)
       {
               
               for(int j=i-1;j>=0;j--)
               {
                    if(groups[j]!=groups[i] && 1+dp[j]>dp[i])
                    {
                        dp[i]=1+dp[j];
                        path[i]=j;
                    }
               }
       }

       auto maxi=max_element(begin(dp),end(dp))-begin(dp);

       vector<string>ans;

       for(int i=maxi;i!=-1;i=path[i])
       {
          ans.push_back(words[i]);

       }

       reverse(ans.begin(),ans.end());
       return ans;

        


        
    }
};