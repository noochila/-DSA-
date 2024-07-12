class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        int ans = 0;

        // Function to remove substrings and calculate score
        auto removeSubstring = [](string& s, char a, char b, int score) -> int {
            stack<char> st;
            int points = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == a && c == b) {
                    st.pop();
                    points += score;
                } else {
                    st.push(c);
                }
            }
            // Reconstruct string after removals
            string new_s;
            while (!st.empty()) {
                new_s.push_back(st.top());
                st.pop();
            }
            reverse(new_s.begin(), new_s.end());
            s = new_s;
            return points;
        };

        if (x > y) {
            ans += removeSubstring(s, 'a', 'b', x);
            ans += removeSubstring(s, 'b', 'a', y);
        } else {
            ans += removeSubstring(s, 'b', 'a', y);
            ans += removeSubstring(s, 'a', 'b', x);
        }

        return ans;
    }
};
