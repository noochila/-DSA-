class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int k = pattern.size();
        int n = nums.size();
        int ans = 0;
        int k2 = k + 1;

        for (int i = 0; i < n - k2 + 1; i++) {
            bool isMatching = true;

            for (int j = 0; j < k; j++) {
                if (pattern[j] == 1 && nums[i + j + 1] <= nums[i + j]) {
                    isMatching = false;
                    break;
                }
                if (pattern[j] == 0 && nums[i + j + 1] != nums[i + j]) {
                    isMatching = false;
                    break;
                }
                if (pattern[j] == -1 && nums[i + j + 1] >= nums[i + j]) {
                    isMatching = false;
                    break;
                }
            }

            if (isMatching) {
                ans++;
            }
        }

        return ans;
    }
};