
class Solution {
public:
    bool check(int k, std::vector<int>& a, int n) {
        int stores = 0;

        for (int i = 0; i < a.size(); i++) {
            stores += ceil((double)a[i] / (double)k);

            if (stores > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, std::vector<int>& a) {
        long long low = 1;
        long long high =*max_element(a.begin(),a.end());  
        long long ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, a, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (long long)ans;
    }
};
