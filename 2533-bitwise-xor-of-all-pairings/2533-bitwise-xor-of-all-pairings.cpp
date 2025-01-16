class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 % 2 == 1 && n2 % 2 == 1) {
            int x = 0;
            for (auto it : nums1)
                x ^= it;

            for (auto it : nums2)
                x ^= it;

            return x;

        } else if (n1 % 2 == 0 && n2 % 2 == 0) {
            return 0;

        } else if (n1 % 2 == 1 && n2 %2 == 0) {
            int x = 0;
            for (auto it : nums2)
                x ^= it;
            return x;

        } else {
            int x = 0;
            for (auto it : nums1)
                x ^= it;

            return x;
        }
    }
};