//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 int decodeHelper(string &digits, int index, vector<int> &memo)
{

    int n = digits.length();

    // Base case: If we reach the end of the string,
    // return 1 as it signifies a valid decoding.
    if (index >= n)
    {
        return 1;
    }

    // If the value is already calculated for this
    // index, return it.
    if (memo[index] != -1)
    {
        return memo[index];
    }

    int ways = 0;

    // Single-digit decoding: check if current digit is not '0'.
    if (digits[index] != '0')
    {
        ways = decodeHelper(digits, index + 1, memo);
    }

    // Two-digit decoding: check if next two digits are valid.
    if ((index + 1 < n) && ((digits[index] == '1' && digits[index + 1] <= '9') ||
                            (digits[index] == '2' && digits[index + 1] <= '6')))
    {

        ways += decodeHelper(digits, index + 2, memo);
    }

    // Memoize the result for the current index.
    memo[index] = ways;
    return ways;
}

// Function to count decoding ways for the entire string.
int countWays(string &digits)
{
    int n = digits.length();

    // Create a memoization vector initialized to -1.
    vector<int> memo(n, -1);

    return decodeHelper(digits, 0, memo);
}
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends