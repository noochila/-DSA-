class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Sort meetings by their start time and then by end time
        sort(meetings.begin(), meetings.end());

        // Merge intervals
        vector<vector<int>> merged;
        merged.push_back(meetings[0]);

        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= merged.back()[1] + 1) {
                // Overlapping or adjacent intervals, merge them
                merged.back()[1] = max(merged.back()[1], meetings[i][1]);
            } else {
                // Non-overlapping interval, add to merged list
                merged.push_back(meetings[i]);
            }
        }

        int ans = 0;

        // Calculate uncovered days before the first merged interval
        if (merged[0][0] > 1) {
            ans += merged[0][0] - 1;
        }

        // Calculate gaps between merged intervals
        for (int i = 1; i < merged.size(); ++i) {
            ans += merged[i][0] - merged[i - 1][1] - 1;
        }

        // Calculate uncovered days after the last merged interval
        if (days > merged.back()[1]) {
            ans += days - merged.back()[1];
        }

        return ans;
    }
};
