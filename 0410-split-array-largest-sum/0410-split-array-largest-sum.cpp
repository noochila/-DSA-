class Solution {
public:
   
    bool check(int mid,vector<int>&nums,int k)
    {
        int s=1;
        int ct=0;
        for(auto it:nums)
        {
            if(ct+it>mid)
            {
                s++;
                ct=it;
            }else
            ct+=it;
        }

        if(s>k)
        return true;
        else
        return false;
    }


    int splitArray(vector<int>& nums, int k) {

        if(nums.size()<k)
        return 0;


        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(check(mid,nums,k))
            low=mid+1;
            else
            high=mid-1;
        }
        return high+1;
        
    }
};