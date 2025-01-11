class Solution {
public:
    bool canConstruct(string s, int k) {

        if(s.size()<k)
        return false;

        map<char, int> mp;
        for (auto it : s)
            mp[it]++;

        int odd = 0;
        int even = 0;
        for (auto it : mp) {
            if (it.second % 2)
                odd++;
            else
                even++;
        }

        if(odd>k)
        return false;
        else
        return true;
       
     

    }
    // messi
    // smeis
    // ss m e i
};