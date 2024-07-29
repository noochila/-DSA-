class Solution {
public:
    int numTeams(vector<int>& a) {
        int n = a.size();
        vector<int> ans1(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] > a[j])
                    count++;
            }

            ans1[i] = count;
        }

        int count = 0;
        for (int k = 2; k < n; k++) {

            for (int j = k - 1; j >= 0; j--) {
                if (a[j] < a[k]) {
                    count += ans1[j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] < a[j])
                    count++;
            }

            ans1[i] = count;
        }

       
        for (int k = 2; k < n; k++) {

            for (int j = k - 1; j >= 0; j--) {
                if (a[j] > a[k]) {
                    count += ans1[j];
                }
            }
        }

        return count;
    }
};