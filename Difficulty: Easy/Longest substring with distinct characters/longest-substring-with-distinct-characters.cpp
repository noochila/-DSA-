//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
    int len=0;
    int n=s.size();
    
    int i=0;
    int j=0;
    map<char,int>mp;
    while(j<n)
    {
        
        mp[s[j]]++;
        while(i<j && mp.size()<(j-i+1))
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            mp.erase(s[i]);
            
            i++;
        
        }
        len=max(len,j-i+1);
        j++;
        
        
    }
    
    
    return len;
     
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends