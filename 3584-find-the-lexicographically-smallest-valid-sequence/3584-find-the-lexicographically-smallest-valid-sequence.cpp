class Solution {
public:
    set<tuple<int, int, int>> s;

    bool solve(string& word1, string& word2, int i, int j, vector<int>& temp,
               int done) {

        if (j == word2.size()) {
            return true;
        }

        if (i == word1.size()) {
            return false;
        }

        if (s.find(make_tuple(i, j, done)) != s.end())
            return false;

        if (word1[i] == word2[j]) {
            if (solve(word1, word2, i + 1, j + 1, temp, done)) {
                temp.push_back(i);
                return true;
            }

        } else {
            bool check = false;

            if (done == 0) {
                check |= solve(word1, word2, i + 1, j + 1, temp, 1);
                if (check) {
                    temp.push_back(i);
                    return true;
                }
            }

            while (i < word1.size() && word1[i] != word2[j])
                i++;

            if (i < word1.size()) {
                check = solve(word1, word2, i + 1, j + 1, temp, done);

                if (check) {
                  
                  temp.push_back(i);
                    return check;
                }
            }
        }
        s.insert(make_tuple(i, j, done));
        return false;
    }

    vector<int> validSequence(string word1, string word2) {
        vector<int> temp;
        vector<int> result;

        if (solve(word1, word2, 0, 0, temp, 0)) {
            reverse(temp.begin(), temp.end());
            return temp;
        }

        return {};
    }
};
