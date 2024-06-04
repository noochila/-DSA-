class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lowercase(26, 0); // For lowercase letters
        vector<int> uppercase(26, 0); // For uppercase letters

        // Count frequencies of each letter
        for(int i = 0; i < s.size(); i++) {
            if(islower(s[i])) {
                lowercase[s[i] - 'a']++;
            } else if(isupper(s[i])) {
                uppercase[s[i] - 'A']++;
            }
        }

        int ans = 0;
        bool odd = false;

        // Calculate the length of the longest palindrome
        for(int i = 0; i < 26; i++) {
            if(lowercase[i] % 2 == 0) {
                ans += lowercase[i];
            } else {
                ans += lowercase[i] - 1;
                odd = true;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(uppercase[i] % 2 == 0) {
                ans += uppercase[i];
            } else {
                ans += uppercase[i] - 1;
                odd = true;
            }
        }

        // If there was at least one character with an odd count, we can add one to the answer
        if(odd) {
            ans += 1;
        }

        return ans;
    }
};
