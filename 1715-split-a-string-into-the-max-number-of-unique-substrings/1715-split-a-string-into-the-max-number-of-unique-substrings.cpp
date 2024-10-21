class Solution {
public:
    int maxval = 0;

    void solve(string& s, int ind, map<string, int> mp)

    {
        if (ind >= s.size()) {
            int k = mp.size();

            maxval = max(maxval, k);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            string temp = s.substr(ind, i-ind+1);
            mp[temp]++;

            solve(s, i + 1, mp);
            mp[temp]--;
            if (mp[temp] == 0)
                mp.erase(temp);
        }
    }

    int maxUniqueSplit(string s) {

        map<string, int> mp;

        solve(s, 0, mp);

        return maxval;
    }
};