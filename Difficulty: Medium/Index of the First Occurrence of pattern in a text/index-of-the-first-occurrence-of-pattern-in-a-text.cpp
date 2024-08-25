//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        
       int m=text.size();
        int n=pat.size();
        
        int j=0;
        for(int i=0;i<m;i++)
        {
            if(text[i]==pat[j])
            {
                int ans=i;
                int k=0;
                while(k<n)
                {
                    if(text[i+k]!=pat[j+k])
                    {
                        break;
                    }
                    k++;
                }
                if(k==n)
                {
                    return ans;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends