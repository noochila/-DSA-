//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[' or s[i]=='{' or s[i]=='(')
            st.push(s[i]);
            else if(!st.empty() && ( (st.top()=='(' and s[i]==')') or (st.top()=='{'  and s[i]=='}') or( st.top()=='[' and s[i]==']')))
            st.pop();
            else
            return false;
        
        }
        
        if(st.size()==0)
        return true;
        else
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends