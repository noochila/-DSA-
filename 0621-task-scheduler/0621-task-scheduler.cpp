class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        unordered_map<char, int> mp;
        for (auto it : tasks) mp[it]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : mp) pq.push({it.second, it.first});

        int ans = 0;

        while (pq.size() > 0) {
            if (pq.top().first == 1) {
                ans += pq.size();
                return ans;
            }
            auto temp = pq.top();
            pq.pop();
            temp.first -= 1;

            vector<pair<int, char>> arr;
            ans++;
            arr.push_back({temp.first, temp.second});  // Correctly store the decremented task

            for (int i = 0; i < n; i++) {
                if (pq.size() > 0) {
                    arr.push_back({pq.top().first - 1, pq.top().second});
                    pq.pop();
                }
                ans += 1;
            }

            for (auto it : arr) {
                if (it.first > 0) pq.push(it);
            }
        }
        return ans;
    }
};
