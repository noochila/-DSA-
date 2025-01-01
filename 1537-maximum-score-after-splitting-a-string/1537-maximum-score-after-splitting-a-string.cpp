class Solution {
public:
    int maxScore(string s) {

        vector<int>prefix(s.size(),0);
        vector<int>suffix(s.size()+1,0);


        prefix[0]=s[0]=='0';
        suffix[s.size()-1]=s[s.size()-1]=='1';

        for(int i=1;i<s.size();i++)
        prefix[i]=prefix[i-1]+(s[i]=='0');

        for(int i=s.size()-2;i>=0;i--)
        suffix[i]=suffix[i+1]+(s[i]=='1');

        if(prefix[s.size()-1]==s.size())
        return s.size()-1;

        if(suffix[0]==s.size())
        return s.size()-1;

        int ans=0;
        for(int i=0;i<s.size()-1;i++)
        {
            ans=max(ans,prefix[i]+suffix[i+1]);
        }
       
         

        return ans;
        
    }
};