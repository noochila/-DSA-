class Solution {
public:
    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> dp(n, 1e9);
        // dp[0] = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j <= nums[i]; j++) {
        //         if (i + j < n) {
        //             dp[i + j] = min(dp[i + j], dp[i] + 1);
        //         }
        //     }
        // }

        // return dp[n - 1];

        int n = nums.size();
        int start = 0;
        int end = 0;
        int c = 0;

        while (end<n-1) {

           int far=0;
            for(int j=start;j<=end;j++)
            {
                far=max(far,j+nums[j]);

            }
            start=end+1;
            end=far;
            c++;
        }

        return c;
    }
};
