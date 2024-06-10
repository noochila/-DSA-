class Solution {
public:
    int characterReplacement(string s, int k) {

        map<char,int>mp;

        int maxf=0;
        int len=0;

        int i=0;
        int j=0;
        int n=s.size();
        

        while(j<n)
        {
            mp[s[j]]++;
            maxf=max(maxf,mp[s[j]]);

            if(j-i+1-maxf<=k)
            {
                len=max(len,j-i+1);
                j++;
            }else
            {
                mp[s[i]]--;
              
                i++;
                j++;
            }


        }
        return len;

      



        
        
    }
};