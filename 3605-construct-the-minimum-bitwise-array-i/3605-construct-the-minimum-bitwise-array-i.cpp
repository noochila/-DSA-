class Solution {
public:
    int get(int n) { return n | (n + 1); }
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans(nums.size(),-1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= 10000; j++) {
                if (get(j) == nums[i]) {
                    ans[i] = j;
                    break;
                }
            }
        }

        return ans;
    }
};