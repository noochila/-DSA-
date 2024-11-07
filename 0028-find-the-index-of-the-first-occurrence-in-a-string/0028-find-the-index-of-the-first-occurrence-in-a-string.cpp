class Solution {
public:

        vector<int> LPS;
    vector<int> build(string p) {
        int n = p.size();
        LPS.resize(n);

        LPS[0] = 0;
        int i = 1;
        int len = 0;

        while (i < n) {
            if (p[i] == p[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = LPS[len - 1];
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }

    int KMP(string &s,string &p)
    {
        
    int i = 0;
    int j = 0;
    int n = s.size();
    int m = p.size();
    vector<int> ans;

    while (i < n)
    {
        if (s[i] == p[j])
        {
            i++, j++;
        }

        if (j == m)
        {
            ans.push_back(i - j);
            j = LPS[j - 1];
        }
        else if (s[i] != p[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return ans.size()?ans[0]:-1;
    }

    int strStr(string s, string p) {

        build(p);
        return KMP(s,p);


    }
};