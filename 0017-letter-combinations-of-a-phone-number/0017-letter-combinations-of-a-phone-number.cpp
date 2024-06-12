class Solution {

public:
    map<int, vector<char>> mp;
    vector<string> ans;


    void generate(string digits,int ind,string temp)
    {

        if(ind>=digits.size())
        {
            ans.push_back(temp);
            return;
        }


        for(int i=0;i<mp[digits[ind]-'0'].size();i++)
        {
            generate(digits,ind+1,temp+mp[digits[ind]-'0'][i]);

        }


    }
    vector<string> letterCombinations(string digits) {

        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        if (digits.size() == 0)
            return ans;

        generate(digits, 0, "");
        sort(ans.begin(), ans.end());

        return ans;
    }
};