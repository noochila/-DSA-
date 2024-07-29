class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
        
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        // for(int j=1;j<=t.size();j++){
        //     dp[0][j]=0;
        // }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];

        
    }
};


//Memoization all test cases passed
// class Solution {
// public:
// int func(string s, string t,int i,int j,vector<vector<int>> &dp){
//     if(j<0){
//         return 1;
//     }
//     if(i<0){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(s[i]==t[j]){
//         return dp[i][j]=(func(s,t,i-1,j-1,dp)+func(s,t,i-1,j,dp));
//     }
//     else{
//         return dp[i][j]=func(s,t,i-1,j,dp);
//     }
// }
//     int numDistinct(string s, string t) {
//         vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
//         int i=s.size()-1;
//         int j=t.size()-1;
//         return func(s,t,i,j,dp);
        
//     }
// };