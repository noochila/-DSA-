//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        
        
        int i=s1.size()-1;
        int j=s2.size()-1;
        int carry=0;
       
        string ans="";
        
        while(i>=0 && j>=0)
        {
            if(s1[i]=='1' && s2[j]=='1')
            {
                if(carry==0)
                ans='0'+ans;
                else
                ans='1'+ans;
                
                carry=1;
            }else if((s1[i]=='1' && s2[j]=='0') || (s1[i]=='0' && s2[j]=='1'))
            {
                if(carry)
                {
                    ans='0'+ans;
                    carry=1;
                    
                }else
                {
                    ans='1'+ans;
                }
            }else
            {
                if(carry)
               { ans='1'+ans;
               carry=0;}
                else
                ans='0'+ans;
            }
            // cout<<ans<<endl;
            i--;
            j--;
        }
    
        while(i>=0)
        {
            if(carry)
            {
                if(s1[i]=='0')
               { ans='1'+ans;
                   carry=0;
               }
                else
               { ans='0'+ans;
                   carry=1;
               }
            }else
            {
                ans=s1[i]+ans;
            }
            i--;
        }
        
        
          while(j>=0)
        {
            if(carry)
            {
                if(s2[j]=='0')
               { ans='1'+ans;
                   carry=0;
               }
                else
               { ans='0'+ans;
                   carry=1;
               }
            }else
            {
                ans=s2[j]+ans;
            }
            j--;
        }
        
        
        if(carry)
        ans='1'+ans;
        
        int k=0;
        while(ans[k]=='0')
        k++;
        
        
        return ans.substr(k);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends