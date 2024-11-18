class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         vector<int>prefix(nums.size());
        
        for(int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + (nums[i] > nums[i - 1] ? 1 : 0);
        }
        
        for(int i = 0; i + 2 * k - 1 < nums.size(); i++) {
            if((prefix[i + k - 1] - prefix[i] == k - 1) && (prefix[i + 2*k - 1] - prefix[i + k] == k - 1)) {
                return true;
            }
        }
        
        return false;
        
        
    }
};