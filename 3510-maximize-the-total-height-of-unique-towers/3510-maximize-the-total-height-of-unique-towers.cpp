class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
        // Sort the array in ascending order
        sort(a.begin(), a.end());

        int n = a.size();
        long long sum = 0;  // To store the sum of the tower heights
        int prev = 1e9 + 1; // Start with a large number as the previous assigned height

        // Iterate over the array from the last (tallest) tower to the first
        for (int i = n - 1; i >= 0; i--) {
            // Assign the largest possible height that is unique
            int curr_height = min(prev - 1, a[i]);

            // If the assigned height is less than 1, it's impossible to assign valid heights
            if (curr_height < 1) {
                return -1;
            }

            // Add the current height to the total sum
            sum += curr_height;
            // Update the previous height for the next iteration
            prev = curr_height;
        }

        return sum;
    }
};
