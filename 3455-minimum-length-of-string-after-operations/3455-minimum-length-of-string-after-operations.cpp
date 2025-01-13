class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        unordered_map<char,int>mp;

        for(auto it:s)
        mp[it]++;

        int ans=0;

        for(auto it:mp)
        {
            if(it.second%2==0)
            ans+=2;
            else
            ans+=1;
        }
        return ans;
    }
};
