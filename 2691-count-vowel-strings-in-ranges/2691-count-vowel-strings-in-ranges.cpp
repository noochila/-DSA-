class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            string s = words[i - 1];
            int wn = s.size();
            char first = s[0];
            char second = s[wn - 1];

            cout << first << " " << second << endl;
            bool check1 = false;
            bool check2 = false;

            if (first == 'a' || first == 'e' || first == 'i' || first == 'o' ||
                first == 'u')
                check1 = true;

            if (second == 'a' || second == 'e' || second == 'i' ||
                second == 'o' || second == 'u')
                check2 = true;

            if (check1 && check2)
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = prefix[i - 1];

            // cout<<prefix[i]<<endl;
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            ans.push_back(prefix[y + 1] - prefix[x]);
        }

        return ans;
    }
};