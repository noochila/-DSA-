class Solution {
public:
    vector<long long> prefixsums;

    bool check(long long sec, int mountainHeight, vector<int>& workerTimes) {
        long long remainingHeight = mountainHeight;

        for (int i = 0; i < workerTimes.size(); i++) {
            long long k = sec / workerTimes[i];
            int height = upper_bound(prefixsums.begin(), prefixsums.end(), k) - prefixsums.begin();
            height -= 1;  

            if (height >= 0) {
                remainingHeight -= height;
                if (remainingHeight <= 0)
                    return true;  
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
      
        prefixsums.resize(mountainHeight + 1, 0);
        for (int i = 1; i <= mountainHeight; i++)
            prefixsums[i] = prefixsums[i - 1] + i;

       
        long long low = 0;
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        long long high = 1LL * mountainHeight * (mountainHeight + 1) * maxTime / 2;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, mountainHeight, workerTimes)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
