class Solution {
public:
    bool isCircularSentence(string sentence) {

        stringstream s(sentence);
        string temp = "";
        vector<string> store;

        while (getline(s, temp, ' ')) {
            store.push_back(temp);
        }

        for (int i = 0; i < store.size() - 1; i++) {
            if (store[i][store[i].size() - 1] != store[i + 1][0])
                return false;
        }

        string last = store[store.size() - 1];
        if (store[0][0] == last[last.size() - 1])
            return true;
        else
            return false;
    }
};