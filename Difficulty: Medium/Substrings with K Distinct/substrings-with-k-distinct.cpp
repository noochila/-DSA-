//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int count(string&s,int k)
    {
        int i=0;
        int j=0;
        int n=s.size();
        map<char,int>mp;
        int c=0;
        while(j<n)
        {
            mp[s[j]]++;
            
            if(mp.size()<=k)
            {
                c+=(j-i+1);
                j++;
            }else 
            {
                while(i<j && mp.size()>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                    mp.erase(s[i]);
                    i++;
                    
                    if(mp.size()==k)
                    c+=(j-i+1);
                }
                j++;
            }
  
            
        }
        
        return c;
    }
  
    int countSubstr(string str, int k) {
        // code here.
        int c1=count(str,k);
        int c2=count(str,k-1);
        // cout<<c1<<" "<<c2<<endl;
        return c1-c2;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends