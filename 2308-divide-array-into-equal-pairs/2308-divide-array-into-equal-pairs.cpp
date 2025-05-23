class Solution {
public:
    bool divideArray(vector<int>& nums) {

        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        for(auto it:mp)
        {
            if(it.second%2)
            return false;
        }
        return true;
    }
};