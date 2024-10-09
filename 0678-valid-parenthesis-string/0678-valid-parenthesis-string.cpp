#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        // stack<int> st; // Using int stack to store indices of '(' and '*'
        //  int count

        // for (int i = 0; i < s.size(); ++i) {
        //     if (s[i] == '(') {
        //         st.push(i);
        //     } else if (s[i] == '*') {
        //         stars.push(i);
        //     } else if (s[i] == ')') {
        //         if (!st.empty()) {
        //             st.pop(); // Match '(' with ')'
        //         } else if (!stars.empty()) {
        //             stars.pop(); // Use '*' to match ')'
        //         } else {
        //             return false; // No valid '(' or '*' to match ')'
        //         }
        //     }
        // }

        // // Match remaining '(' with '*' if possible
        // while (!st.empty() && !stars.empty()) {
        //     if (st.top() < stars.top()) {
        //         st.pop();
        //         stars.pop();
        //     } else {
        //         break; // Remaining '(' cannot be matched with '*'
        //     }
        // }

        // return st.empty(); // If stack is empty, all '(' are matched

        int open = 0;
        int close = 0;
        int n = s.size();

        for (int i = 0; i < n/2; i++) {
            if (s[i] == '(' || s[i] == '*')
                open++;
            else
                open--;
            if (s[n - i - 1] == ')' || s[n - i - 1] == '*')
                close++;
            else
                close--;

            if (open < 0 || close < 0)
                return false;
        }

        return true;
    }
};