class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string temp = "";

        for (auto it : s) {
            if (it == '(') {
                st.push(temp);
                temp = "";
            } else if (it == ')') {
                reverse(temp.begin(), temp.end());
                if (!st.empty()) {
                    temp = st.top() + temp;
                    st.pop();
                }
            } else {
                temp += it;
            }
        }

        return temp;
    }
};
