class Solution {
public:
    bool solve(int ind, int n, string& pattern, string& ans, vector<bool>& used) {
        if (ind > n) 
            return true;

        for (int i = 1; i <= n + 1; i++) {
            if (!used[i] && 
                ((ans.back() - '0' < i && pattern[ind - 1] == 'I') || 
                 (ans.back() - '0' > i && pattern[ind - 1] == 'D'))) {
                
                ans.push_back('0' + i);
                used[i] = true;
                
                if (solve(ind + 1, n, pattern, ans, used))
                    return true;
                
                ans.pop_back();
                used[i] = false;
            }
        }
        return false;
    }

    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<bool> used(n + 2, false);

        for (int i = 1; i <= n + 1; i++) {
            string temp = "";
            temp.push_back('0' + i);
            used[i] = true;

            if (solve(1, n, pattern, temp, used))
                return temp;

            used[i] = false;
        }
        return "";
    }
};
