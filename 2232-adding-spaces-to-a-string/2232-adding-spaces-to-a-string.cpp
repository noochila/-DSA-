class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string temp="";

        set<int> mp(spaces.begin(),spaces.end());

        for(int i=0;i<s.size();i++)
        {
            if(mp.find(i)!=mp.end())
            temp+=" ";
            
            temp+=s[i];

        }
        return temp;
        
    }
};