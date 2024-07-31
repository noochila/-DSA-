class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, ele2 = 0, c1 = 0, c2 = 0;
        int n = nums.size();
        vector<int> ans;

        // First pass to find potential candidates
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) {
                c1++;
            } else if (nums[i] == ele2) {
                c2++;
            } else if (c1 == 0) {
                ele1 = nums[i];
                c1 = 1;
            } else if (c2 == 0) {
                ele2 = nums[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        // Second pass to confirm the candidates
        c1 = c2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ele1) c1++;
            else if (nums[i] == ele2) c2++;
        }

        // Check if they appear more than n / 3 times
        int mini = n / 3 + 1;
        if (c1 >= mini) ans.push_back(ele1);
        if (c2 >= mini) ans.push_back(ele2);

        return ans;
    }
};
