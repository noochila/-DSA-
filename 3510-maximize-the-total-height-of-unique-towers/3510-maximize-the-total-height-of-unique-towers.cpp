class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
       
        sort(a.begin(), a.end());

        int n = a.size();
        long long sum = 0; 
        int prev = 1e9 + 1; 
       
        for (int i = n - 1; i >= 0; i--) {
           
            int curr_height = min(prev - 1, a[i]);

          
            if (curr_height < 1) {
                return -1;
            }

           
            sum += curr_height;
          
            prev = curr_height;
        }

        return sum;
    }
};
