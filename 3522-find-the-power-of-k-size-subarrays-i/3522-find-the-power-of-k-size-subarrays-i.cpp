class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i <= n - k; ++i) {
            // Extract the subarray of size k
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            
            // Check if the subarray is sorted and has consecutive elements
            bool is_consecutive_sorted = true;
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    is_consecutive_sorted = false;
                    break;
                }
            }
            
            // If the subarray is sorted and consecutive, add the maximum element
            if (is_consecutive_sorted) {
                ans.push_back(*max_element(subarray.begin(), subarray.end()));
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
