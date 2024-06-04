//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:


string binaryNextNumber(string s) {
    int n = s.size();
    string ans = s;

    // Traverse from the end to the beginning
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            ans[i] = '1'; // Change the first '0' to '1'
            ans.erase(0, ans.find_first_not_of('0')); // Remove leading zeros
            return ans;
        } else {
            ans[i] = '0'; // Change '1' to '0'
        }
    }

    // If all bits were '1', the new number is "1000...0"
    ans = '1' + ans;
    ans.erase(0, ans.find_first_not_of('0')); // Remove leading zeros
    return ans;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends