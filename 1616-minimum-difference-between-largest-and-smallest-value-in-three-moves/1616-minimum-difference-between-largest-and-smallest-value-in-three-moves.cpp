class Solution {
public:
    int minDifference(vector<int>& nums) {
	int n = nums.size();
	// for 1 <= n <= 4 we can always change all the numbers to equal numbers
	if(n < 5)
		return 0;
	
	// first 4 elements
	partial_sort(nums.begin(), nums.begin() + 4, nums.end());
	// last 4 elements
    partial_sort(nums.rbegin(), nums.rbegin() + 4, nums.rend(), greater<int>());
	
	int min_diff = INT_MAX;
	for(int i = 0, j = n - 4; i < 4; ++i, ++j)
		min_diff = min(min_diff, nums[j] - nums[i]);
        
	return min_diff;
}
};