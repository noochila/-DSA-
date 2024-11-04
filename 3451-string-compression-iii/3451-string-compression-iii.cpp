class Solution {
public:
    string compressedString(string word) {

        string temp = "";

        int i = 0;
        int j = 0;

        while (j < word.size()) {
            if (word[j] == word[i] && j - i < 9) {
                j++;

            } else {
                int len = j - i;
                char c = word[i];
                word.erase(0, j - i);
                // cout << word << endl;
                temp += to_string(len);
                temp += c;
                j = 0;
            }
        }

        if (word.size() > 0) {
            temp += to_string(j - i);
            temp += word[0];
        }

        return temp;
    }
};