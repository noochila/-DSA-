//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
          if(d*9<s){return "-1";}
        vector<int>v(d,0);
        int i=d-1;
        while(s>9){
            v[i--]=9;
            s-=9;
        }
        v[i]=s;
        if(v[0]==0){v[0]=1; v[i]--;}
        string ans="";
        for(auto &b: v){ans+=(b+'0');}
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends