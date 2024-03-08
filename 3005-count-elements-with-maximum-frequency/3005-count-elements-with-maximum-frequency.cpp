class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        
        int count=0;
        int maxi=0;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
          }
        
        for(auto it:mp)
        {
            if(it.second>maxi)
            maxi=it.second;
       }
        
        for(auto it:mp)
        {
            if(it.second==maxi)
                count+=it.second;
        }
        
        return count;
        
        
        
        
        
    }
};