class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {

        unordered_map<string,int>mp;
        for(auto it:bannedWords)
        mp[it]++;

        int c=0;
        for(auto it:message)
        {
            if(mp.find(it)!=mp.end())
            c++;
        }
        if(c>=2)
        return true;
        else
        return false;
        
    }
};