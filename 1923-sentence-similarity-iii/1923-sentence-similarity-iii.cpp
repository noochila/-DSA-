class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {

        if (s1.size() < s2.size())
            return areSentencesSimilar(s2, s1);

        vector<string> w1;
        vector<string> w2;

        stringstream s(s1);
        string temp;
        while (getline(s, temp, ' ')) {
            w1.push_back(temp);
        }
        stringstream ss(s2);
        while (getline(ss, temp, ' ')) {
            w2.push_back(temp);
        }

            int i = 0;
           int j = w1.size() - 1;
            int k = 0;
          int  l = w2.size() - 1;

            while (i < w1.size() && k < w2.size() && w1[i] == w2[k]) {
                i++, k++;
            }

            while (l>=k && w1[j] == w2[l]) {
                j--, l--;
            }

          return l<k;
        }
    };