class Solution {
public:
    long long minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char ch : t)
            mp[ch]++;

        int i = 0, j = 0;
        long long ans = 0;
        int n = s.size();
        int count = mp.size(); 

        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--; 
            }

            while (count == 0) { 
                ans += (n - j); 

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                        count++;
                }
                i++; 
            }

            j++; 
        }

        return ans;
    }

    long long validSubstringCount(string word1, string word2) {
        return minWindow(word1, word2);
    }
};
