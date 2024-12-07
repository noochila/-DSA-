class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
  
    int n = strength.size();
    int minTime = INT_MAX;

   
    sort(strength.begin(), strength.end());
    do {
        int time = 0;
        int currentFactor = 1; 

        for (int i = 0; i < n; ++i) {
            int energyNeeded = strength[i];
            
            int requiredMinutes = (energyNeeded + currentFactor - 1) / currentFactor; 
            time += requiredMinutes;
            currentFactor += K; 
        }

     
        minTime = min(minTime, time);
    } while (next_permutation(strength.begin(), strength.end()));

    return minTime;
   
    }
};