class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        vector<vector<int>> prev;
        if (clips[0][0] != 0)
            return -1; // Check if the first clip starts from 0

        prev.push_back(clips[0]); // Push the first clip into prev

        for (int i = 1; i < clips.size(); i++) {
            if (prev.back()[1] < clips[i][1] && prev.back()[0] == clips[i][0]) {
                prev.pop_back();
                prev.push_back(clips[i]);
            }
            if (prev.size() >= 2 && (prev[prev.size() - 2][1] >= clips[i][0] &&
                                     prev.back()[1] <= clips[i][1])) {
                prev.pop_back();
                prev.push_back(clips[i]);
            }
            if (prev.back()[1] >= clips[i][0] && prev.back()[1] < clips[i][1]) {
                prev.push_back(clips[i]);
            }
        }

        for (int i = 0; i < prev.size(); i++) {
            cout << prev[i][0] << " " << prev[i][1] << endl;
            if (prev[i][0] <= time && prev[i][1] >= time)
                return i + 1;
        }

        return -1;
    }
};
