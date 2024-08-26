//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
   int fn(string &str, string &ptr, int i, int j,vector<vector<int>>& dp){
        if(i>=str.size() && j>=ptr.size()){
            return 1;
        }
        if(j>=ptr.size()){
            return 0;
        }
        if(i>=str.size()){
            while(j<ptr.size()){
                if(ptr[j]!='*'){
                    return 0;
                }
                j++;
            }
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(ptr[j]=='?' || str[i]==ptr[j]){
            return ans=fn(str,ptr,i+1,j+1,dp);
        }
        if(ptr[j]=='*'){
            ans=fn(str,ptr,i+1,j,dp) || fn(str,ptr,i,j+1,dp);
        }
        return dp[i][j]=ans;
    }
    int wildCard(string ptr, string str) {
        // code here
        vector<vector<int>> dp(str.size()+1,vector<int> (ptr.size()+1,-1));
        return fn(str,ptr,0,0,dp);
    }


};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends