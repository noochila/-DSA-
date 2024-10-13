class Solution {
public:
      bool checkWindow(vector<int> &patternFreq, vector<int> &windowFreq, string& s, string& pattern, int start) {
        int frequencyDiffCount = 0;
        int charMismatchCount = 0;

        for (int i = 0; i < 26; i++) {
            frequencyDiffCount += abs(patternFreq[i] - windowFreq[i]);
            if (frequencyDiffCount > 2) return false; 
        }
        for (int i = start + pattern.length() - 1; i >= start; i--) {
            if (s[i] != pattern[i - start]) {
                charMismatchCount++;
                if (charMismatchCount > 1) return false; 
            }
        }
        return true;
    }

    int minStartingIndex(string& s, string& pattern) {
        vector<int> patternFreq(26,0);
        vector<int> windowFreq(26,0);
        int patterSize = pattern.size();
        for (char c : pattern) {
            patternFreq[c - 'a']++;
        }
        int i;
        for (i = 0; i < patterSize && i < s.length(); i++) {
            windowFreq[s[i] - 'a']++;
        }
        for (i = patterSize; i < s.length(); i++) {
            if (checkWindow(patternFreq, windowFreq, s, pattern, i - patterSize)) {
                return i - patterSize;
            }

            windowFreq[s[i] - 'a']++;
            windowFreq[s[i - patterSize] - 'a']--;
        }
        if (checkWindow(patternFreq, windowFreq, s, pattern, i - patterSize)) {
            return i - patterSize;
        }

        return -1; 
    }
};