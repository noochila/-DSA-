class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> vec = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> group;
        unordered_map<int, queue<int>> link;
        int g = 0;

        group[nums[0]] = g;
        link[g].push(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (abs(nums[i] - nums[i - 1]) > limit) {
                g++;
            }

            group[nums[i]] = g;
            link[g].push(nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int k = group[vec[i]];

            ans.push_back(link[k].front());
            cout << ans.back() << endl;
            link[k].pop();
        }
        return ans;
    }
};