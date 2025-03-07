class Solution {
public:
    vector<bool> getPrimes(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right) {

        vector<bool>ans=getPrimes(right);
        vector<int>temp;

        for(int i=left;i<=right;i++)
        {
            if(ans[i])
            temp.push_back(i);
        }

         int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

        for(int i = 1; i < temp.size(); i++) {
            int diff = temp[i] - temp[i-1];

            if(diff < minDiff) {
                minDiff = diff;
                result = {temp[i-1], temp[i]};
            }
        }

        return result;
    }
};