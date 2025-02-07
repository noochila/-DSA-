class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        map<int,int>freq;
        set<int>s;
        map<int,int>mp;
        vector<int>ans;


        for(auto it:queries)
        {
            int ball=it[0];
            int color=it[1];

            if(mp.find(ball)==mp.end())
            {
                mp[ball]=color;
                s.insert(color);
                freq[color]++;

            }else
            {
                int prevcolor=mp[ball];
                freq[prevcolor]--;
                if(freq[prevcolor]==0)
                {
                    freq.erase(prevcolor);
                    s.erase(prevcolor);
                }
                mp[ball]=color;
                s.insert(color);
                freq[color]++;

            }
            ans.push_back(s.size());


        }
        return ans;
        
    }
};