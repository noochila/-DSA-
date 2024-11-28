//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int myAtoi(char *s) {
        bool neg = false; // To track if the number is negative
        long ans = 0;     // Use long to handle overflow during computation
        int i = 0;

        // Skip leading spaces
        while (s[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (s[i] == '-' || s[i] == '+') {
            neg = (s[i] == '-');
            i++;
        }

        // Convert digits to integer until a non-digit character is encountered
        while (isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow/underflow
            if (ans > INT_MAX) {
                return neg ? INT_MIN : INT_MAX;
            }

            i++;
        }

        // Apply sign if needed
        if (neg) {
            ans = -ans;
        }

        return static_cast<int>(ans); // Cast back to int before returning
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends