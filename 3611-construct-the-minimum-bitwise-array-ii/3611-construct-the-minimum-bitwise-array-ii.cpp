class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool happed = false;
            int anst = nums[i];
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    int temp = nums[i] & (~(1 << j));

                    if ((temp | (temp + 1)) == nums[i]) {
                        cout << temp << endl;

                        happed = true;

                        anst = min(anst, temp);
                    }
                }
            }

            if (!happed)
                ans.push_back(-1);
            else
                ans.push_back(anst);
        }

        return ans;
    }
};