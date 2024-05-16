class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        if (n == 1) {
            if (cost[0] > gas[0])
                return -1;
            else
                return 0;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(gas[i] - cost[i]);
        int i = 0;

        vector<int> points;

        while (i < n) {
            if (ans[i] > 0)
                points.push_back(i);

            i++;
        }

        for (int k = 0; k < points.size(); k++) {
            i = points[k];
            int rem = ans[i];

            int j = ((i + 1) % n);
            while (j != i && j < n) {
                rem += ans[j];
                if (rem < 0)
                    break;

                j = (j + 1) % n;
            }
            if (i == j)
                return i;
        }
        return -1;
    }
};