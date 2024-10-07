class Solution {
public:
    int minLength(string s) {

        while (true) {
            if (s.find("AB") != string::npos) {
                s.erase(s.find("AB"), 2);
            }

            if (s.find("CD") != string::npos) {
                s.erase(s.find("CD"), 2);
            }

        

            if (s.find("AB") == string::npos && s.find("CD") == string::npos )
                break;
        }

        return s.size();
    }
};