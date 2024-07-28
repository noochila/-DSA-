class Solution {
public:
    bool solve(string& word, string& pattern) {

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        int start = 0;
        for (int i = 0; i < word.size(); i++) {
            if (mp1.find(word[i]) == mp1.end()) {
                mp1[word[i]] = start;
                start++;
            }
        }
        start=0;

        for (int i = 0; i < word.size(); i++) {
            if (mp2.find(pattern[i]) == mp2.end()) {
                mp2[pattern[i]] = start;
                start++;
            }
        }

        for(int i=0;i<word.size();i++)
        {
            if(mp1[word[i]]!=mp2[pattern[i]])
            return false;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {

        vector<string> ans;
        for (auto it : words) {
            if (solve(it, pattern))
                ans.push_back(it);
        }

        return ans;
    }
};