class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> e[n], E[n];
        for (int i = 1; i < n; i++) e[parent[i]].push_back(i);

        vector<int> vec[26];
        auto dfs1 = [&](auto &&self, int sn, int fa) -> void {
            int c = s[sn] - 'a';
            if (sn > 0) {
                if (vec[c].size() > 0) E[vec[c].back()].push_back(sn);
                else E[fa].push_back(sn);
            }
            vec[c].push_back(sn);
            for (int fn : e[sn]) self(self, fn, sn);
            vec[c].pop_back();
        };
        dfs1(dfs1, 0, -1);

        vector<int> ans(n);
        auto dfs2 = [&](auto &&self, int sn) -> int {
            ans[sn] = 1;
            for (int fn : E[sn]) ans[sn] += self(self, fn);
            return ans[sn];
        };
        dfs2(dfs2, 0);
        return ans;
    }
};