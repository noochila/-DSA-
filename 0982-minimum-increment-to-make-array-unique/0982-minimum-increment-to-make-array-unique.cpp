#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // Sort the input array
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is not greater than the previous element
            if (nums[i] <= nums[i - 1]) {
                // Calculate the number of increments needed
                int increment = nums[i - 1] - nums[i] + 1;
                // Increment the current element to make it unique
                nums[i] += increment;
                // Add the number of increments to the count
                count += increment;
            }
        }

        return count;
    }
};
