class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int ind, int n, int target,
               vector<int> temp) {
        if (ind >= n) {

            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if(target<0)
        return ;

        if (target - candidates[ind] >= 0) {
            temp.push_back(candidates[ind]);
            solve(candidates, ind, n, target - candidates[ind], temp);
            temp.pop_back();
        }

        solve(candidates, ind + 1, n, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        int n = candidates.size();
        vector<int> temp;

        solve(candidates, 0, n, target, temp);

        return ans;
    }
};