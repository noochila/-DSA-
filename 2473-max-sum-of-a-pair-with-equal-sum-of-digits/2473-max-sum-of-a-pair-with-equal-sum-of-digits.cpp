class Solution {
public:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> mp;
        
        for (auto it : nums) {
            int digitsum = getDigitSum(it);
            mp[digitsum].insert(it);
        }

        int ans = -1;  // Initialize with -1 to handle cases where no pair exists.
        
        for (auto& it : mp) {
            if (it.second.size() > 1) {
                auto rit = it.second.rbegin();
                int lastele = *rit;
                int lastsecond = *(++rit); // Get the second largest element
                ans = max(ans, lastele + lastsecond);
            }
        }
        return ans;
    }
};
