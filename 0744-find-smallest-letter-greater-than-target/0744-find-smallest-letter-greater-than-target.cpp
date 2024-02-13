class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int x = upper_bound(letters.begin(), letters.end(), target) -
                letters.begin();

        if (x == letters.size())
            return letters[0];

        else
            return letters[x];
    }
};