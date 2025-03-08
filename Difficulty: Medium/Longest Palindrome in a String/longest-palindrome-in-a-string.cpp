//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        
        int len = 1, start = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        // Odd-length palindrome
        int oddLen = 1, oddStart = i;
        for (int idx = 1; i - idx >= 0 && i + idx < n; idx++) {
            if (s[i - idx] == s[i + idx]) {
                int currLen = 2 * idx + 1;
                if (currLen > oddLen) {
                    oddLen = currLen;
                    oddStart = i - idx;
                }
            } else break;
        }

        // Even-length palindrome
        int evenLen = 0, evenStart = i;
        for (int idx = 0; i - idx >= 0 && i + idx + 1 < n; idx++) {
            if (s[i - idx] == s[i + idx + 1]) {
                int currLen = 2 * (idx + 1);
                if (currLen > evenLen) {
                    evenLen = currLen;
                    evenStart = i - idx;
                }
            } else break;
        }

        // Update longest palindrome found
        if (oddLen > len) {
            len = oddLen;
            start = oddStart;
        }
        if (evenLen > len) {
            len = evenLen;
            start = evenStart;
        }
    }

    return s.substr(start, len);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends