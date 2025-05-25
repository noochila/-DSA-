class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string, int> mp;
        int count = 0;

        for (auto it : words)
            mp[it]++;

        bool flag = false;

        for (int i = 0; i < words.size(); i++) {

            if (words[i][0] != words[i][1]) {
                string rev = words[i];
                reverse(rev.begin(), rev.end());

                count += min(mp[words[i]], mp[rev]) * 4;

                mp.erase(words[i]);
                mp.erase(rev);

            } else {

                int r = mp[words[i]];

                if (r % 2 == 0) {
                    count += r * 2;
                } else {
                    if (flag == false) {
                        flag = true;
                        count += r * 2;
                    } else {
                        count += (r - 1) * 2;
                    }
                }

                mp.erase(words[i]);
            }
        }

        return count;
    }
};