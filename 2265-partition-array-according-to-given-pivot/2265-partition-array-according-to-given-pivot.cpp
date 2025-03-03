class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int>a1;
        vector<int>a2;
        vector<int>a3;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            a1.push_back(nums[i]);
            else if(nums[i]>pivot)
            a2.push_back(nums[i]);
            else 
            a3.push_back(nums[i]);

        }

        for(int i=0;i<a3.size();i++)
        a1.push_back(a3[i]);

        for(int i=0;i<a2.size();i++)
        a1.push_back(a2[i]);
        return a1;
    }
};