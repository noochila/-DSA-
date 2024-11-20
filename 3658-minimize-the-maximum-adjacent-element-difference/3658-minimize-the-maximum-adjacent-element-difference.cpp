class Solution {
public:
    // Helper function to check if a given maxDiff is feasible
    bool isValidDifference(vector<int> nums, int maxDiff) {

        int min_element = INT_MAX;
        int max_element = INT_MIN;
        // Traverse through the nums array
        for (int i = 0; i < nums.size(); i++) { // n
            // When an element is not -1 and is adjacent to a -1, compute possible values
            if (nums[i] != -1 && (i && nums[i-1] == -1 || (i != nums.size()-1) && nums[i+1] == -1)) {
                min_element = min(min_element, nums[i]);  // Minimum possible value for the element
                max_element = max(max_element, nums[i]);  // Maximum possible value for the element
            }
        }

        // Calculate the minimum and maximum values considering the allowed difference
        int minValue = min_element + maxDiff;  // The lower bound value - X
        int maxValue = max_element - maxDiff;  // The upper bound value - Y

        // flag1 denotes if we were successful to place minValue first
        // flag2 denotes if we were successful to place maxValue first
        int flag1 = 1;
        int flag2 = 1;

        vector<int> copyNums = nums;
        // Now, for each -1 in the array, try to fill it with either `minValue` or `maxValue`
        for (int i = 0; i < copyNums.size(); i++) { // n
            if (copyNums[i] == -1) {  // If it's a missing value
                // Try replacing with `minValue` first
                if (
                    (i == 0 || abs(copyNums[i-1] - minValue) <= maxDiff) &&  // Check left neighbor
                    (i == (copyNums.size() - 1) || copyNums[i+1] == -1 || abs(copyNums[i+1] - minValue) <= maxDiff))  // Check right neighbor
                {
                    copyNums[i] = minValue;  // Replace with `minValue`
                } else {
                    copyNums[i] = maxValue;  // Otherwise, replace with `maxValue`
                }
            }
        }

        // After replacing all -1 values, check if the difference between adjacent elements is within `maxDiff`
        for (int i = 0; i < copyNums.size()-1; i++) {
            if (abs(copyNums[i] - copyNums[i+1]) > maxDiff) {  // If any difference exceeds `maxDiff`, make flag1 = 0
                flag1 = 0;
            }
        }

        copyNums = nums;
        for (int i = 0; i < copyNums.size(); i++) { // n
            if (copyNums[i] == -1) {  // If it's a missing value
                // Try replacing with `maxValue` first
                if (
                    (i == 0 || abs(copyNums[i-1] - maxValue) <= maxDiff) &&  // Check left neighbor
                    (i == (copyNums.size() - 1) || copyNums[i+1] == -1 || abs(copyNums[i+1] - maxValue) <= maxDiff))  // Check right neighbor
                {
                    copyNums[i] = maxValue;  // Replace with `maxValue`
                } else {
                    copyNums[i] = minValue;  // Otherwise, replace with `minValue`
                }
            }
        }
        // After replacing all -1 values, check if the difference between adjacent elements is within `maxDiff`
        for (int i = 0; i < copyNums.size()-1; i++) {
            if (abs(copyNums[i] - copyNums[i+1]) > maxDiff) {  // If any difference exceeds `maxDiff`, make flag2 = 0
                flag2 = 0;
            }
        }

        // Return OR value of flag1 and flag2
        return flag1 || flag2;
    }

    // Main function to find the minimum possible difference between adjacent elements
    int minDifference(vector<int>& nums) {    
        int missingCount = 0;

        // Count how many missing values (-1) are in the array
        for (int x: nums) if (x == -1) missingCount++;

        // If no missing values, calculate the maximum difference between adjacent elements
        if (missingCount == 0) {
            int maxDiff = 0;
            for (int i = 0; i < nums.size()-1; i++) { // n
                maxDiff = max(maxDiff, abs(nums[i] - nums[i+1]));  // Find the largest difference
            }
            return maxDiff;
        } 
        // If all elements are missing, the minimum difference is 0 since we can set them to the same value
        else if (missingCount == nums.size()) return 0;

        // Perform binary search to find the minimum possible `maxDiff`
        int low = 0;
        int high = 1000000005;  // A large enough number to represent the upper bound
        int ans;
        // Binary search for the minimum `maxDiff`
        while (low <= high) { // log2(10^9)
            int mid = (low + high) / 2;  // Find the midpoint of the current range

            // Test if the current maxDiff is feasible
            if (isValidDifference(nums, mid)) {
                high = mid - 1;  // If feasible, try a smaller `maxDiff`
                ans = mid;
            } else {
                low = mid + 1;  // If not feasible, try a larger `maxDiff`
            }
        }

        // Return the smallest `maxDiff` that worked
        return ans;
    }
};

// tc - O(n*log2(10^9))
// sc - O(n)