class Solution {
public:
    int countPalindromicSubsequence(string s) {

        map<char, vector<int>> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }

        int c = 0;
        for (auto it : mp) {
            if (it.second.size() >= 2) {
                int start = *(it.second).begin();
                int end = (it.second).back();
                set<char> st;
                for (int i = start + 1; i < end; i++) {
                    st.insert(s[i]);
                
                }

            //    cout<<it.first<<" "<<st.size()<<endl;
                c += st.size();
            }
        }
        return c;
    }
};