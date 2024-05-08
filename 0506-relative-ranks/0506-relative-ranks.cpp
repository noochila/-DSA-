class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        vector<string> ans(score.size()); // Initialize ans with appropriate size

        priority_queue<pair<int, int>> pq;

        int n = score.size();

        for (int i = 0; i < n; i++)
            pq.push({score[i], i});

        auto temp = pq.top();
        ans[temp.second] = "Gold Medal";
        pq.pop();

        if (!pq.empty()) {
            temp = pq.top();
            ans[temp.second] = "Silver Medal";
            pq.pop();
        }

        if (!pq.empty()) {
            temp = pq.top();
            ans[temp.second] = "Bronze Medal";
            pq.pop();
        }

        int i = 4; // Start with 4th place

        while (!pq.empty()) {

            auto temp = pq.top();

            ans[temp.second] = to_string(i); // Convert integer to string
            pq.pop();
            i++;
        }

        return ans;
    }
};
