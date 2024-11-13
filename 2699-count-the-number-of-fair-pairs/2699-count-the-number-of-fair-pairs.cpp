class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        //0 1 4 4 5 7

        /*
        


        */

        for(int i=0;i<nums.size();i++)
        {
            int start=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int end=lower_bound(nums.begin()+i+1,nums.end(),upper-nums[i]+1)-nums.begin();

            count+=(end-start);
        }

        return count;

        //

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int sum = nums[i] + nums[j];
        //         if (sum >= lower && sum <= upper)
        //             count++;
        //     }
        // }

        // return count;


        




    }
};