class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
  
    int n = strength.size();
    int minTime = INT_MAX;

    // Try all permutations of the lock-breaking order
    sort(strength.begin(), strength.end());
    do {
        int time = 0; // Total time
        int currentFactor = 1; // Initial sword energy factor

        for (int i = 0; i < n; ++i) {
            int energyNeeded = strength[i];
            // Calculate the time needed to reach the required energy
            int requiredMinutes = (energyNeeded + currentFactor - 1) / currentFactor; // Ceiling of energyNeeded / currentFactor
            time += requiredMinutes;
            currentFactor += K; // Update factor after breaking the lock
        }

        // Update the minimum time
        minTime = min(minTime, time);
    } while (next_permutation(strength.begin(), strength.end()));

    return minTime;
   
    }
};