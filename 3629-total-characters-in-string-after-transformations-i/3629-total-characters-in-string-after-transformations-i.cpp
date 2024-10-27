class Solution {
public:
    int mod = 7 + 1e9;

    int lengthAfterTransformations(string s, int t) {

        vector<int> mp(26, 0);
        for (auto it : s) {
            mp[it - 'a']++;
        }

        for (int i = 0; i < t; i++) {
        vector<int> temp(26, 0);
            for (int j= 0; j < 25; j++) {
                temp[j + 1] = (temp[j + 1] + mp[j]) % mod;
            }

            temp[0] = (temp[0] + mp[25]) % mod;
            temp[1] = (temp[1] + mp[25]) % mod;

            mp = temp;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + mp[i]) % mod;
            cout<<mp[i]<<endl;
        }
        return ans;
    }
};