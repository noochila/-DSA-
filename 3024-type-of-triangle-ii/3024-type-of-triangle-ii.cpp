class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0]+nums[1]<=nums[2])
            return "none";
         if(nums[1]+nums[2]<=nums[0])
            return "none";
        
         if(nums[2]+nums[0]<=nums[1])
            return "none";
        
       
        set<int> s;
        for(auto it:nums)
            s.insert(it);
        
        if(s.size()==1)
            return "equilateral";
        
        if(s.size()==2)
            return "isosceles";
        if(s.size()==3)
            return "scalene";
        return "";
        
    }
};