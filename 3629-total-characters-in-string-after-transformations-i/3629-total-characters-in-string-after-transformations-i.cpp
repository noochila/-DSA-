class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        long long len = s.length();

        vector<long long> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(int step = 1; step <= t; step++) {
            vector<long long> newFreq(26, 0);
            len = 0;
            for(int i = 0; i < 26; i++) {
                if(i == 25) { // 'z'
                    newFreq[0] = (newFreq[0] + freq[25]) % MOD; // 'a'
                    newFreq[1] = (newFreq[1] + freq[25]) % MOD; // 'b'
                    len = (len + 2 * freq[25]) % MOD;
                } else {
                    newFreq[i + 1] = (newFreq[i + 1] + freq[i]) % MOD;
                    len = (len + freq[i]) % MOD;
                }
            }
            freq = newFreq;
        }

        return len % MOD;
    }
};