//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    public:
    string decodedString(string s) {
        int n = s.length();
        return parse(s, 0).first; // Start parsing from index 0
    }

private:
    pair<string, int> parse(string& s, int i) {
        string r = "";
        int n = s.length();
        while (i < n) {
            auto result = parseItem(s, i);
            string p = result.first;
            i = result.second;
            if (p == string(1, '-1')) { // Stopper value
                break;
            }
            r += p;
        }
        return {r, i};
    }

    pair<string, int> parseItem(string& s, int i) {
        int n = s.length();
        if (i >= n) {
            return {"", n};
        }
        if (s[i] == '[') {
            return parse(s, i + 1); // Recursively parse inside brackets
        }
        if (s[i] == ']') {
            return {string(1, '-1'), i + 1}; // Stop parsing when we reach ']'
        }
        if (!isdigit(s[i])) {
            return {string(1, s[i]), i + 1}; // If it's a letter, add it to the result
        }
        int e = 0;
        while (i < n && isdigit(s[i])) {
            e = e * 10 + (s[i] - '0');
            i++;
        }
        auto result = parseItem(s, i); // Parse the string inside the brackets
        string r = result.first;
        i = result.second;
        string multiplied = "";
        for (int j = 0; j < e; ++j) {
            multiplied += r;
        }
        return {multiplied, i};
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends