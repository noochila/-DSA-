class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int n = customers.size();

        double ans = 0;
        int curr = 0;

        for (int i = 0; i < n; i++) {

            int arrival = customers[i][0];
            int waiting = customers[i][1];
            if (curr > arrival)
                curr = curr + waiting;
            else {
                curr =  arrival+waiting;
            }
            ans += (curr - arrival);
            cout<<curr<<" "<<ans<<endl;
        }

        return (double)(ans) / (double)(n);
    }
};