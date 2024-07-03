class Solution {
public:

   bool check(vector<int>& nums,int val,int thresh)
   {
         int c=0;
       for(auto it:nums)
       {
        c+=ceil((double)it/(double)val);
        if(c>thresh)
        return false;

       }

       return true;
   }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int low=1;
        int high=*max_element(nums.begin(),nums.end());

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,mid,threshold))
            {
            high=mid-1;
            }else
                low=mid+1;
        }
        return low;
    }
};