class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        vector<int> vec(k, 0);
        vector<int> range{-100000, 100000};

        while (true) {
            int mini = INT_MAX;
            int maxi = INT_MIN;
            int minInd = 0;
            for (int i = 0; i < k; i++) {
                int listInd = i;
                int vecInd = vec[i];
                int ele = nums[listInd][vecInd];
                if (ele < mini) {
                    mini = ele;
                    minInd = i;
                }
                maxi = max(maxi, ele);
            }

            if (maxi - mini < range[1] - range[0]) {
                range[0] = mini;
                range[1] = maxi;
            } else if (maxi - mini == range[1] - range[0]) {
                if (mini < range[0]) {
                    range[0] = mini;
                    range[1] = maxi;
                }
            }

            int nextInd = vec[minInd] + 1;
            if (nextInd >= nums[minInd].size())
                break;

            vec[minInd] = nextInd;
        }

        return range;
    }
};