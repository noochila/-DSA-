class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

            unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];

                if (mp.find(prod) != mp.end()) {
                    vector<int> s;
                    s.push_back(nums[i]);
                    s.push_back(nums[j]);
                   for(int k=0;k<mp[prod];k++)
                   ans.push_back(s);
                }
                mp[prod]++;
            }
        }



        return ans.size() * 4*2;
    }
};