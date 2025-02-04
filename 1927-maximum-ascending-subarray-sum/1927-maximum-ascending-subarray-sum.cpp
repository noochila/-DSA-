class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

         int currentSum = nums[0]; 
        int maxSum = nums[0];    

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; 
            } else {
                maxSum = max(maxSum, currentSum); 
                currentSum = nums[i]; 
            }
        }

     
        maxSum = max(maxSum, currentSum);

        return maxSum;
        
    }
};