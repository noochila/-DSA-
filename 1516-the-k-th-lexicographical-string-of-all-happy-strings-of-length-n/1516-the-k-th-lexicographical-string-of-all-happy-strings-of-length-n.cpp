class Solution {
public:
    int count = 0;
    string result = "";

    void solve(string &temp, int n, int k) {
        if (temp.size() == n) {
            count++;
            if (count == k) {
                result = temp;
            }
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (temp.empty() || temp.back() != ch) {
                temp.push_back(ch);
                solve(temp, n, k);
                temp.pop_back();
                if (!result.empty()) return;  // Stop recursion once result is found
            }
        }
    }

    string getHappyString(int n, int k) {
        string temp = "";
        solve(temp, n, k);
        return result;
    }
};
