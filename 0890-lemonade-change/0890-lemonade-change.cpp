class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int n = bills.size();

        vector<int> store(3, 0);
        for (int i = 0; i < n; i++) {

            if (bills[i] == 5) {
                store[0]++;

            } else if (bills[i] == 10) {
                if (store[0] > 0) {
                    store[1]++;
                    store[0]--;
                } else {
                    return false;
                }
            } else {

                if (store[1] > 0 && store[0] > 0) {
                    store[1]--;
                    store[0]--;
                    store[2]++;

                }else if(store[0]>=3)
                {
                    store[2]++;
                    store[0]-=3;

                } else {
                    return false;
                }
            }
        }

        return true;
    }
};