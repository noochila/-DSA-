class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long totalCost = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int start = s[i] - 'a'; 
            int end = t[i] - 'a';  

            if (start == end) continue; 

            
            int forwardSteps = (end - start + 26) % 26;
            long long forwardCost = 0;
            for (int step = 0, idx = start; step < forwardSteps; step++) {
                forwardCost += nextCost[idx];
                idx = (idx + 1) % 26; 
            }

            
            int backwardSteps = (start - end + 26) % 26;
            long long backwardCost = 0;
            for (int step = 0, idx = start; step < backwardSteps; step++) {
                backwardCost += previousCost[idx];
                idx = (idx - 1 + 26) % 26;
            }

          
            totalCost += min(forwardCost, backwardCost);
        }

        return totalCost;
    }
};
