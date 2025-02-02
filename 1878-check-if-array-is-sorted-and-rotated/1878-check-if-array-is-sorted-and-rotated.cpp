class Solution {
public:
    bool check(vector<int>& nums) {
        int i=0;

       while(i<nums.size())
       {
         rotate(nums.begin(), nums.begin() + 1, nums.end());
         if(is_sorted(nums.begin(),nums.end()))
         return true;
         i++;
       }
       return false;
        
    }
};