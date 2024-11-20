class Solution {
public:
    int takeCharacters(string s, int k) {

        unordered_map<char,int>mp;
        for(auto it:s)
        mp[it]++;
       
           if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;


        int i=0;
        int j=0;
        int n=s.size();
        int c=0;
        int ans=1e9;
        while(j<n)
        {
            mp[s[j]]--;
            c++;
            while(mp[s[j]]<k)
            {
                mp[s[i]]++;
                c--;
                i++;

            }
            ans=min(ans,n-c);
            j++;
        }
        return ans;

        
    }
};