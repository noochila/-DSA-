#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        // Using tuple: (time, x, y, status)
        priority_queue<tuple<int, int, int, bool>,
                       vector<tuple<int, int, int, bool>>, greater<>>
            pq;
        pq.push({0, 0, 0,
                 true}); // Initial state: time=0, (x, y) = (0, 0), status=false

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> final_ans(n, vector<int>(m, INT_MAX));
        final_ans[0][0] = 0;

        while (!pq.empty()) {
            auto [time, x, y, status] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return time; // Reached the destination
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextTime;
                    bool nextStatus;
                    if (status) {
                        nextTime = max(time, moveTime[nx][ny]) + 1;
                        nextStatus=false;
                    } else {
                        nextTime = max(time, moveTime[nx][ny]) + 2;
                        nextStatus=true;
                    }

                    if (nextTime < final_ans[nx][ny]) {
                        final_ans[nx][ny] = nextTime;
                        pq.push({nextTime, nx, ny, nextStatus});
                    }
                }
            }
        }
        return -1;
    }
};
