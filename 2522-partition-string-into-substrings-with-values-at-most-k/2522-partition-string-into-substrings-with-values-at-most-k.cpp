class Solution {
public:
    int minimumPartition(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;

        while (j < n) {
            // Check for non-numeric characters
            if (!isdigit(s[j])) {
                return -1;
            }
            if (stoll(s.substr(i, j - i + 1)) <= k) {
                j++;
            } else {
                if (i != j && stoll(s.substr(i, j - i)) <= k) {
                    ans++;
                    i = j;
                } else {
                    return -1;
                }
            }
        }
        ans++;

        return ans;
    }
};