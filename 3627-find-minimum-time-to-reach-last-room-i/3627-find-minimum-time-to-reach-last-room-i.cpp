#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        // Corrected the declaration of the priority queue
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> final_ans(n, vector<int>(m, INT_MAX));
        final_ans[0][0]=0;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int time = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;

            // cout << time << " " << x << " " << y << endl;

            if (x == n - 1 && y == m - 1) {
                return time;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nextTime = max(time, moveTime[nx][ny] )+1;
                    if (nextTime < final_ans[nx][ny]) {
                        final_ans[nx][ny] = nextTime;
                        pq.push({nextTime, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};
