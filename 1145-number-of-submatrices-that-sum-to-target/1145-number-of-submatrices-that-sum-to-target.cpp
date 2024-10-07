class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 1;col < m; col++) {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        for (int col = 0; col < m; col++) {

            for (int j = col; j < m; j++) {

                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;

                for (int row = 0; row < n; row++) {

                    sum += (matrix[row][j]) - (col > 0 ? matrix[row][col - 1] : 0);

                    int req = sum - target;
                    if (mp.find(req) != mp.end())
                        ans += mp[req];

                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};