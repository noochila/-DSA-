class Solution {
public:

    int smallest(int n)
{
        for(int i=2;i*i<=n;i++)
            {
                if(n%i==0)
                    return i;
            }
    return n;
}


    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int op=0;

        for(int i=n-2;i>=0;i--)
            {
                if(nums[i]>nums[i+1])
        
                {
                    nums[i]=smallest(nums[i]);
                        op++;
                        
                }

                if(nums[i]>nums[i+1])
                        return -1;
                    
            }

        return op;
      
    }
};