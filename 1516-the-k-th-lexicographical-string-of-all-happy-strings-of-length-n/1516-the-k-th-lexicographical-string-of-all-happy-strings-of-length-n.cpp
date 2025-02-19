class Solution {
public:
    set<string> st;  // Stores happy strings in lexicographical order

    void solve(string temp, int n, int ind) {
        if (ind >= n) {
            st.insert(temp);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (temp.back() != ch) {
                temp.push_back(ch);
                solve(temp, n, ind + 1);
                temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        for (char ch = 'a'; ch <= 'c'; ch++) {
            string temp = "";
            temp.push_back(ch);
            solve(temp, n, 1);
        }

        if (st.size() < k)
            return "";

        return *next(st.begin(), k - 1);  // Corrected k-th element retrieval
    }
};
