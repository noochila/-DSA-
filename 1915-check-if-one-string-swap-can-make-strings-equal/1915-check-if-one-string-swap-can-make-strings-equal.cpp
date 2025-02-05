class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int c = 0;
        if (s1.size() != s2.size())
            return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i])
                c++;
        }

        if (c == 2 || c == 0) {
            vector<int> a(26, 0);
            vector<int> b(26, 0);
            for (auto it : s1)
                a[it - 'a']++;

            for (auto it : s2)
                b[it - 'a']++;

            for (int i = 0; i < 26; i++)
                if (a[i] != b[i])
                    return false;

            return true;
        } else
            return false;
    }
};