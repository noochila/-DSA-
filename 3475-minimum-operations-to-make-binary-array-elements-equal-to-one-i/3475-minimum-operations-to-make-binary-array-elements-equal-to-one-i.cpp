class Solution {
public:
    int minOperations(vector<int>& nums) {
       
        int i=0;
        int n=nums.size();
        int c=0;

        while(i<n)
        {
            if(nums[i]==0)
            {
                if(i+2<n)
                {
                    nums[i+1]=!nums[i+1];
                    nums[i+2]=!nums[i+2];
                    i++;
                    c++;

                }else
                return -1;
            }else
            i++;
        }
        return c;
        
    }
};