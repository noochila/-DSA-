class Solution {
public:
    vector<int> process(vector<int> nums, vector<vector<int>>& queries, int k) {
        vector<int> pdiff(nums.size() + 1);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            pdiff[l] -= val;
            pdiff[r+1] += val;
        }

        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            curr += pdiff[i];
            nums[i] += curr;
        }

        return nums;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size() + 1;

        while (l != r) {
            int m = (l + r) / 2;

            vector<int> res = process(nums, queries, m);

            bool valid = true;
            for (int x: res) {
                if (x > 0) valid = false;
            }

            if (valid) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        if (l == queries.size() + 1) return -1;
        return l;
    }
};