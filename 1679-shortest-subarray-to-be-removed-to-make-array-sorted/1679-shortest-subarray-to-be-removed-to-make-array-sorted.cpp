class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int ans;
        int i = 0;
        int n = arr.size();
        int j = n - 1;
        while (j > 0 && (arr[j - 1] <= arr[j])) {
            j--;
        }

        ans = j;

        while (i < j && (i == 0 || (arr[i] >= arr[i - 1]))) {
         
            while (j < n && (arr[i] > arr[j]))
                j++;
            ans = min(ans, j - i - 1);

               i++;
        }

        return ans;
    }
};