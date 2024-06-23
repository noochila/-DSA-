//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        
        vector<int> ans;
        
        set<int> s;
        
        int start=0;
        int end=0;
        
        for(char ch:str)
        {
            if(ch=='(')
            
           { 
               start++;
               ans.push_back(start);
                   end=start;
               
           }
            else  if(ch==')')
            
            {
                
                
              while(s.find(end)!=s.end()){
                  end--;
            
            }
                ans.push_back(end);
                s.insert(end);
                end--;
                
            }
            
        }
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends