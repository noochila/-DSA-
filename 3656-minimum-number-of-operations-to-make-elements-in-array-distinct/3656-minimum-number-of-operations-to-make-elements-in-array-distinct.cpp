class Solution {
public:
    bool check(map<int, int>& mp) {
        for (int i = 1; i <= 100; i++) {
            if (mp[i] > 1)
                return false;
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {

        map<int, int> mp;
         int c = 0;
        int n = nums.size();
        for (auto it : nums)
            mp[it]++;
        bool happen = false;

        if (check(mp))
            return 0;
        else {
            int i = 0;
           
            while (i + 2 < n) {
                mp[nums[i]]--;
                mp[nums[i + 1]]--;
                mp[nums[i + 2]]--;
                c++;
                if (check(mp))
                    return c;

                i+=3;
            }

            if (i < n) {
                if (check(mp))
                    return c;
                else
                    return c + 1;
            }
        }
        return c;
    }
};