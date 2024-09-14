

class Solution {
public:
    int temp[33][100000];
    int prefix[33][100000];

    void calculate(int n, vector<int>& nums) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 31; j++) {
                temp[j][i] = (nums[i] & (1 << j) ? 1 : 0);
            }
        }

        for (int i = 0; i < 31; i++)
            prefix[i][0] = temp[i][0];

        for (int i = 0; i < 31; i++) {
            for (int j = 1; j < n; j++) {
                prefix[i][j] = prefix[i][j - 1] + temp[i][j];
            }
        }

        // for (int i = 0; i < 31; i++) {
        //     for (int j = 0; j < n; j++)
        //         cout << prefix[i][j] << " ";

        //     cout << endl;
        // }
        // cout<<endl;
    }

    int calculateAnd(int m, int n) {

        long long x = 0;
        int dis = n - m + 1;

        if (m != 0) {
            for (int i = 0; i <= 31; i++) {

                int currdis = prefix[i][n] - prefix[i][m - 1];

                if (currdis == dis) {

                    x += pow(2, i);
                }
            }

            return x;
        } else {

            for (int i = 0; i <= 31; i++) {

                int currdis = prefix[i][n];
                if (currdis == dis) {

                    x += pow(2, i);
                }
            }

            return x;
        }
    }

    int longestSubarray(vector<int>& nums) {
        // calculate(nums.size(), nums);
        // calculateAnd(2, 3)

        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }
        return ans;
    }
};