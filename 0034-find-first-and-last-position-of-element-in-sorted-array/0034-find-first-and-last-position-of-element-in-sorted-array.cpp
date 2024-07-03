class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(find(nums.begin(),nums.end(),target)==nums.end())
        return {-1,-1};

        else
        {
            int first=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            int last=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
            return {first,last-1};
        }
      
    //   int n=nums.size();

    //     int low=0;
    //     int high=n-1;


    //     while(low<=high)

         




        
        
    }
};