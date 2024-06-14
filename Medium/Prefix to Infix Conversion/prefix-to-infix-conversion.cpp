//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>s;
        
       for (int i = pre_exp.size() - 1; i >= 0; i--) {
        char it = pre_exp[i];
        
        // If the character is an operand, push it to the stack
        if (isalnum(it)) {
            s.push(string(1, it));
        } 
        // If the character is an operator, pop two operands from the stack, combine them
        // with the operator, and push the resulting string back to the stack
        else {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string ans = '(' + op1 + it + op2 + ')';
            s.push(ans);
        }
    }
    
    // The final result is at the top of the stack
    return s.top();
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends