class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int mini1 = 1e9;
        int maxi1 = -1e9;
        int mini2 = 1e9;
        int maxi2 = -1e9;
        int ans = 0;
        sort(arrays.begin(),arrays.end());
        for (int i = 0; i < arrays.size() - 1; i++) {
            // sort(arrays[i].begin(), arrays[i].end());
            // sort(arrays[i + 1].begin(), arrays[i + 1].end());
            mini1 = min(mini1, *arrays[i].begin());
            maxi1 = max(maxi1, *arrays[i].rbegin());
            mini2 = min(mini2, *arrays[i + 1].begin());
            maxi2 = max(maxi2, *arrays[i + 1].rbegin());
            ans = max({maxi2 - mini1, maxi1 - mini2, ans});
        }
        return ans;
    }
};