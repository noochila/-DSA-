class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;

        unordered_map<string, int> mp;
        mp["00000"] = -1;

        string temp = "00000";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == 'a') {
                if (temp[0] == '0')
                    temp[0] = '1';
                else
                    temp[0] = '0';
            } else if (s[i] == 'e') {
                if (temp[1] == '0')
                    temp[1] = '1';
                else
                    temp[1] = '0';
            } else if (s[i] == 'i') {
                if (temp[2] == '0')
                    temp[2] = '1';
                else
                    temp[2] = '0';
            } else if (s[i] == 'o') {
                if (temp[3] == '0')
                    temp[3] = '1';
                else
                    temp[3] = '0';
            } else if (s[i] == 'u') {
                if (temp[4] == '0')
                    temp[4] = '1';
                else
                    temp[4] = '0';
            }

            if (mp.find(temp) == mp.end())
                mp[temp] = i;
            else
                ans = max(ans, i - mp[temp]);
        }

        return ans;
    }
};