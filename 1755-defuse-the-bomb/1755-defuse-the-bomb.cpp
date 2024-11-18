class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        vector<int> ans;
        int n = code.size();

        if (k == 0) {
            for (int i = 0; i < n; i++)
                ans.push_back(0);
            return ans;

        } else if (k < 0) {

            for (int j = 0; j < n; j++) {
            int prev = 0;
                int count = 0;
                int i = j- 1;
                while (count < abs(k)) {
                    prev += code[(i + n) % n];
                    i--;
                    count++;
                }
                ans.push_back(prev);
            }
            return ans;

        } else {


            for (int j = 0; j < n; j++) {
            int prev = 0;
                int i = j + 1;
                int count = 0;

                while (count < k) {
                    prev += code[(i + n) % n];
                    i++;
                    count++;
                }
                ans.push_back(prev);
            }

            return ans;
        }
    }
};