class Solution {
public:
    int largestCombination(vector<int>& a) {

        map<int, int> mp;

        for (int bit = 0; bit < 32; bit++) {

            int and_ = 0xFFFFFFFF;

            for (int i = 0; i < a.size(); i++) {
                if ((and_ & a[i]) & (1 << bit)) {
                    and_ = and_ & a[i];
                    mp[bit]++;

                    // cout<<bit<<" "<<a[i]<<" "<<mp[bit]<<endl;
                }
            }
        }

        int ans = 0;
        for (auto it : mp)
            ans = max(ans, it.second);
        return ans;
    }
};