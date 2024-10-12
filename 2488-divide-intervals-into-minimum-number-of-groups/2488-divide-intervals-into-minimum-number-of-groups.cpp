#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<P, vector<P>, greater<P>> pq;

        int group = 0;

        sort(intervals.begin(), intervals.end());

        for (auto it : intervals) {
            int st = it[0];
            int ed = it[1];

            if (pq.empty()) {
                pq.push({ed, group});
                // cout << st << " " << ed << " " << group << endl;
                group++;
            } else {
                if (pq.top().first < st) {
                    auto temp = pq.top();
                    pq.pop();
                    pq.push({ed, temp.second});
                } else {
                    pq.push({
                        ed,group
                    });
                    group++;
                }
                // cout << st << " " << ed << " " << group << endl;
            }
        }
        return group;
    }
};
