//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  vector<int> LPS;
  
  void buildLPS(string &temp)
  {
      int n=temp.size();
      LPS.resize(n,0);
      int i=1;
      int len=0;
      
      while(i<n)
      {
          if(temp[i]==temp[len])
          {
              len++;
              LPS[i]=len;
              i++;
          }else
          {
              if(len!=0)
              len=LPS[len-1];
              else
              {
                  LPS[i]=0;
                  i++;
              }
          }
      }
  }
    int minChar(string& s) {
        // Write your code here
        
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+"#"+rev;
        
        buildLPS(temp);
        
        int back=LPS.back();
        return s.size()-back;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends