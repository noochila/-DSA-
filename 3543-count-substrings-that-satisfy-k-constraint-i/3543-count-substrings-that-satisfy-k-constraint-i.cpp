class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;

        // Iterate through each possible starting point of substrings
        for (int i = 0; i < s.size(); i++) {
            int zeroCount = 0, oneCount = 0;
            
            // Iterate through each possible ending point of substrings starting at i
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '1')
                    oneCount++;
                else
                    zeroCount++;
                
                // Check if the current substring satisfies the k-constraint
                if (oneCount <= k || zeroCount <= k)
                    ans++;
                else
                    break; // Stop checking further as longer substrings will also fail
            }
        }

        return ans;
    }
};
