#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto temp = word.find(ch);

        if (temp != string::npos) {
            reverse(word.begin(), word.begin() + temp + 1);
        }

        return word;
    }
};
