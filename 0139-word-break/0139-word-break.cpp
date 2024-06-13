// class Solution {
// public:



//     bool check(string s, unordered_set<string>& k)
//     {
//         if(s.size()==0)
//         {

//         return true;
//         }

//         if(k.find(s)!=k.end())
//         {
//             return true;
//         }

    
//             for(int i=0;i<s.size();i++)
//             {
//                 cout<<s.substr(0,i+1)<<endl;
//                 if(k.find(s.substr(0,i+1))!=k.end())
//                 {
                           
//                     if( check(s.substr(i+1),k)==true)
//                     return true;

//                 }

//             }
       
//        return false;
//     }
 
//     bool wordBreak(string s, vector<string>& wordDict) {

//      unordered_set<string> k(wordDict.begin(),wordDict.end());

//         return check(s,k);
        
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && set.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};