class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        int n = *max_element(nums.begin(), nums.end());
        n = k + n;
        vector<int> a(2 * n + 10, 0);

        for (auto it : nums) {
            int x = it;
            int y = it + 2 * k;

            a[x]++;
            a[y + 1]--;
        }

        for (int i = 1; i <= 2 * n; i++)
            a[i] += a[i - 1];

        return *max_element(a.begin(),a.end());

        
    }
};