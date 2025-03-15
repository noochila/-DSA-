class Solution {
public:


    int check(vector<int>& nums, int k)
    {
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=k)
            {

            count++;
            i++;
            }
        }

        return count;

    }
    int minCapability(vector<int>& nums, int k) {


        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        int ans=0;


        while(low<=high)
        {
            int mid=(low+high)/2;

            if(check(nums,mid)>=k)
            {
                ans=mid;

                high=mid-1;


            }else
            {
                 low=mid+1;
            }
         


        }

        return ans;
        
    }
};

