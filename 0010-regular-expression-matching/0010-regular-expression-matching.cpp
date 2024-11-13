// class Solution {
// public:
//     bool solve(string s, string p) {
//         if (p.size() == 0) {
//             if (s.size() == 0)
//                 return true;
//             else
//                 return false;
//         }

//         bool first_char=false;

//         if(s.length()>0 && (s[0]==p[0] || p[0]=='.'))
//         first_char=true;

//         if( p.size()>=2 && p[1]=='*')
//         {
//             bool ntake=solve(s,p.substr(2));
//             bool take=( first_char&& solve(s.substr(1),p));
//             return ntake||take;
//         }else
//         {
//           return ( first_char && solve(s.substr(1),p.substr(1)));

//         }
//     }

//     bool isMatch(string s, string p) { return solve(s, p); }
// };


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        
		dp[0][0] = true;
        for (int j = 2; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = (p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 2] || (((p[j - 2] == '.') || (p[j - 2] == s[i - 1])) && dp[i - 1][j]);
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
};