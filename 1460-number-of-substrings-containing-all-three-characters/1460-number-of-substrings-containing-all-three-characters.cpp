class Solution {
public:
     int numberOfSubstrings(string s) {

        int i=0;
        int j=0;
        int n=s.size();
        int count=0;
        map<char,int>mp;

        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()<3)
            {
                j++;
            }else if(mp.size()==3)
            {
                while(mp.size()==3)
                {
                 count+=n-j;
                 mp[s[i]]--;
                 if(mp[s[i]]==0)
                 mp.erase(s[i]);

                 i++;

                }

                j++;
            }
        }
        return count;
        
    }
};