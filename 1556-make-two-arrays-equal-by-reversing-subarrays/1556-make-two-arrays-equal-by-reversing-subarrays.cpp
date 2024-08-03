class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
    
     map<int,int>mp;
     

    int n=arr.size();
    int m=target.size();

    if(n!=m)
    return false;


    for(int i=0;i<n;i++)
    {
        mp[target[i]]--;
        mp[arr[i]]++;
    }


    for(auto it:mp)
    {
        if(it.second<0)
        return false;
    }

    return true;

        
    }
};