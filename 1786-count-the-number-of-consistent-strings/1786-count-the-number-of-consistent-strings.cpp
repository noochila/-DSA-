class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_map<char,int>mp;

        int c=0;

        for(auto it:allowed)
        mp[it]++;

        for(auto it:words)
        {
            bool check=false;
            for(auto jt:it)
            {
                if(mp.find(jt)==mp.end())
                {
                    check=true;
                    break;
                  
                }
            }

            if(check==false)
            {
               c++;
            }
        }
        return c;


    }
};