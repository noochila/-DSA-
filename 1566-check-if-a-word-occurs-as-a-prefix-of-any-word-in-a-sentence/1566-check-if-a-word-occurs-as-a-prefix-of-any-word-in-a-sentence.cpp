class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        stringstream s(sentence);
        string temp = "";

        int c = 0;
        while (getline(s, temp, ' ')) {

            if (temp.size() >= searchWord.size()) {
                string newstring = temp.substr(0, searchWord.size());
                
                if (newstring == searchWord)
                    return c+1;
            }
            c++;
        }

        return -1;
    }
};