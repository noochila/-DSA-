class Solution {
public:

unordered_map<string,int>mp;

bool solve(int ind,string &temp,int n)
{
    if(ind>=n)
    {
        if(mp.find(temp)==mp.end())
        return true;
        else
        return false;
    }

    temp.push_back('0');
    if(solve(ind+1,temp,n))
    return true;
    temp.pop_back();
    temp.push_back('1');
    if(solve(ind+1,temp,n))
    return true;
    temp.pop_back();
    return false;



}
    
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto it:nums)
        mp[it]++;
       
       string temp="";
       if(solve(0,temp,nums.size()))
       return temp;

       return "";
        
        
    }
};