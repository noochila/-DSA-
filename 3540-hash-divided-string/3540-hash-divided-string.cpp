class Solution {
public:
    string stringHash(string s, int k) {

        int n = s.size();
        string result = "";

        // Traverse the string in chunks of size `k`
        for (int i = 0; i < n; i += k) {
            int sum = 0;

            // Sum the hash values of each character in the substring of length `k`
            for (int j = i; j < i + k; j++) {
                sum += s[j] - 'a';  // Calculate the hash value based on the alphabet index
            }

            // Find the character corresponding to the sum % 26
            char hashedChar = 'a' + (sum % 26);
            result += hashedChar;
        }

        return result;
        
    }
};