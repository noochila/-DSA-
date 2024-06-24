
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mp;

        for (auto it : t)
            mp[it]++;

        int i = 0;
        int j = 0;

        int n = s.size();
        int count = mp.size();
        int len = 1e9;
        int start = 0;
        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            while (count == 0) {
                if (j - i + 1 < len) {
                    len = j - i + 1;
                    start = i;
                }

                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] >0)
                        count++;
                }

                i++;
            }

            j++;
        }

        return len == 1e9 ? "" : s.substr(start, len );
    }
};