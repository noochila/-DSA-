//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        
        
         vector<int> freq1(26, 0), freq2(26, 0); // Frequency arrays for characters in 'a' to 'z'
        
        // Populate frequency array for s1
        for(int i = 0; i < s1.length(); ++i) {
            freq1[s1[i] - 'a']++;
        }
        
        // Populate frequency array for s2
        for(int i = 0; i < s2.length(); ++i) {
            freq2[s2[i] - 'a']++;
        }
        
        // Step 2: Check if every character in s2 is also in s1
        for(int i = 0; i < 26; ++i) {
            if(freq2[i] != 0 && freq1[i] == 0) {
                return -1; // s2 contains characters not in s1, so it can never be a substring
            }
        }
        
        // Step 3: Repeat s1 until it covers the length of s2
        int cnt = 0;
        string temp = ""; // Temporary string to hold repeated s1
        
        // Keep adding s1 to temp until it reaches or exceeds the length of s2
        while(temp.length() < s2.length()) {
            temp += s1; 
            ++cnt;
        }
        
        // Step 4: Check if s2 is a substring of temp
        if(temp.find(s2) != string::npos) {
            return cnt; // If s2 is a substring, return the count of repetitions
        }
        
        // Step 5: One additional repetition to handle edge cases
        ++cnt;
        temp += s1; // Add one more repetition of s1 to temp
        return (temp.find(s2) != string::npos ? cnt : -1); // Final check if s2 is n
         

        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends