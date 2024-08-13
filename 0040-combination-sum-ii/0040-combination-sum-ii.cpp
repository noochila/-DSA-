class Solution {
public:
    set<vector<int>> ans;

    void solve(vector<int>& candidates, vector<int> temp, int target, int ind) {
        if (ind >= candidates.size()) {
            if (target == 0)
                ans.insert(temp);

            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (target - candidates[i] >= 0) {
                temp.push_back(candidates[i]);
                solve(candidates, temp, target - candidates[i], i + 1);
                temp.pop_back();
            }
            solve(candidates, temp, target, i + 1);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(candidates, temp, target, 0);
        vector<vector<int>> finalans(ans.begin(),ans.end());
        return finalans;
    }
};