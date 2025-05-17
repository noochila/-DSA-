class Solution {

    public static void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    public void sortColors(int[] nums) {
        int i = 0;
        int n = nums.length;
        int k = n - 1;
        int j = 0;
        while(j<=k){

            if (nums[j] == 0) {
                swap(nums, i, j);
                i++;
                j++;
            } else if (nums[j] == 1) {
                j++;
            } else {
                swap(nums, j, k);
                k--;

            }

        }

    }
}