class Solution {
public:
    bool solve(vector<int>& s, unordered_map<int, int>& mp, int ind, int n) {
        if (ind >= s.size())
            return true;

        if (s[ind] != 0) 
            return solve(s, mp, ind + 1, n);  

        for (int i = n; i >= 1; i--) {
            if (mp.find(i) == mp.end()) {
                if (i == 1) {
                    s[ind] = i;
                    mp[i] = 1;
                    if (solve(s, mp, ind + 1, n))
                        return true;
                    s[ind] = 0;
                    mp.erase(i);
                } else {
                    int nextind = ind + i;
                    if (nextind < s.size() && s[nextind] == 0) {
                        s[ind] = i;
                        s[nextind] = i;
                        mp[i] = 1;
                        if (solve(s, mp, ind + 1, n))
                            return true;
                        s[ind] = 0;
                        s[nextind] = 0;
                        mp.erase(i);
                    }
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int len = (n - 1) * 2 + 1;
        vector<int> s(len, 0);
        unordered_map<int, int> mp;

        solve(s, mp, 0, n);
        return s;
    }
};
