class Solution {

    vector<vector<string>> ans;

private:
    bool check(int start, int end, string x) {
        while (start < end) {
            if (x[start] != x[end])
                return false;

            start++;
            end--;
        }
        return true;
    }

private:
    void generate(int index, int n, string s, vector<string> x) {
        if (index == n) {
            ans.push_back(x);
            return;
        } else {
            for (int i = index; i < n; i++) {
                if (check(index, i, s)) {
                    x.push_back(s.substr(index, i - index + 1));
                    generate(i + 1, n, s, x);
                    x.pop_back();
                }
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {

        vector<string> x;

        generate(0, s.size(), s, x);
        return ans;
    }
};